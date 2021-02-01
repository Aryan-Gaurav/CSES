#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>    //Read at https://codeforces.com/blog/entry/11080
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/* 
find_by_order(k):- returns itertator to kth largest element in set (0-based)
order_of_key(x):- return number of values strictly less than x
*/
#define lll __int128
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define ar array
#define setbits(x) __builtin_popcountll(x)
#define f(i,l,r) for(ll i=l;i<r;i++)
#define d(i,n,m) for(ll i=n;i>=m;i--)
#define deb(...) cout<<" [" <<#__VA_ARGS__ ": " << (__VA_ARGS__) << "] ";
#define clr(x) memset(x,0,sizeof(x));
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (ll)x.size()
#define P (ll)(1e9+7)
#define PI acosl(-1.0l)
#define mod 998244353
#define pb push_back
#define F first
#define S second
#define IP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fixed(n) cout<<std::fixed<<std::setprecision(n) //use for n digits precision of decimal
/*  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);  */
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
const int MXN = 2e5+139;
ll tree[4*MXN][2],v[MXN];
void build(ll i,ll l,ll r)
{
    if(l==r)
        tree[i][0]=l+v[l],tree[i][1]=v[l]-l;
    else if(l<r)
    {
        ll mid=(l+r)/2;
        build(2*i,l,mid);
        build(2*i+1,mid+1,r);
        tree[i][0]=min(tree[2*i][0],tree[2*i+1][0]);
        tree[i][1]=min(tree[i<<1][1],tree[2*i+1][1]);
    }
}
ll query(ll s,ll e,bool op,ll i,ll l,ll r)
{
    if(max(s,l)>min(r,e))
        return 1e18;
    else if(s<=l && r<=e)
        return tree[i][op];
    else
    {
        ll mid=(l+r)/2;
        return min(query(s,e,op,2*i,l,mid),query(s,e,op,2*i+1,mid+1,r));
    }
}
void update(ll idx,ll val,ll i,ll l,ll r)
{
    if(idx<l || idx>r)
        return;
    else if(l==r)
        tree[i][0]=l+val,tree[i][1]=val-l;
    else
    {
        ll mid=(l+r)/2;
        update(idx,val,2*i,l,mid);
        update(idx,val,2*i+1,mid+1,r);
        f(k,0,2)
            tree[i][k]=min(tree[2*i][k],tree[2*i+1][k]);
    }
}
int main()
{
    IP
    ll n,q;
    cin>>n>>q;
    f(i,1,n+1)
        cin>>v[i];
    build(1,1,n);
    ll op,pos,val;
    while(q--)
    {
        cin>>op;
        if(op^1)
        {
            cin>>pos;
            cout<<min(query(1,pos,1,1,1,n)+pos,query(pos+1,n,0,1,1,n)-pos)<<"\n";
        }
        else
        {
            cin>>pos>>val;
            update(pos,val,1,1,n);
        }
    }
    return 0;
}
