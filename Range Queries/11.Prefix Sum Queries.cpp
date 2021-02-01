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
struct node
{
    ll sum,pre;
};
node tree[4*MXN];
ll v[MXN];
node combine(node a,node b)
{
    node ans;
    ans.sum=a.sum+b.sum;
    ans.pre=max({0LL,a.pre,a.sum+b.pre});
    return ans;
}
void build(ll i,ll l,ll r)
{
    if(l==r)
        tree[i]=node{v[l],max(v[l],0LL)};
    else if(l<r)
    {
        ll mid=(l+r)/2;
        build(2*i,l,mid);
        build(2*i+1,mid+1,r);
        tree[i]=combine(tree[2*i],tree[2*i+1]);
    }
}
node query(ll s,ll e,ll i,ll l,ll r)
{
    if(max(s,l)>min(r,e))
        return node{0,(ll)-1e18};
    else if(s<=l && r<=e)
        return tree[i];
    else
    {
        ll mid=(l+r)/2;
        return combine(query(s,e,2*i,l,mid),query(s,e,2*i+1,mid+1,r));
    }
}
void update(ll idx,ll val,ll i,ll l,ll r)
{
    if(idx<l || idx>r)
        return;
    else if(l==r)
        tree[i]=node{val,max(val,0LL)};
    else
    {
        ll mid=(l+r)/2;
        update(idx,val,2*i,l,mid);
        update(idx,val,2*i+1,mid+1,r);
        tree[i]=combine(tree[2*i],tree[2*i+1]);
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
    ll op,l,r;
    while(q--)
    {
        cin>>op;
        if(op^1)
        {
            cin>>l>>r;
            cout<<query(l,r,1,1,n).pre<<"\n";
        }
        else
        {
            cin>>l>>r;
            update(l,r,1,1,n);
        }
    }
    return 0;
}
