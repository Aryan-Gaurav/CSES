#include <bits/stdc++.h>
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
using namespace std;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
const int MXN = 1e6+176;
ll v[MXN],tree[MXN];
void build(ll i,ll l,ll r)
{
    if(l==r)
        tree[i]=v[l];
    else if(l<r)
    {
        ll mid = (l+r)>>1;
        build(i<<1,l,mid);
        build((i<<1)|1,mid+1,r);
        tree[i] = tree[i<<1] + tree[(i<<1)|1];
    }
}
void update(ll idx,ll val,ll i,ll l,ll r)
{
    if(idx<l || idx>r)
        return;
    if(l==r)
        tree[i] = val;
    else if(l<r)
    {
        ll mid = (l+r)>>1;
        update(idx,val,i<<1,l,mid);
        update(idx,val,(i<<1)|1,mid+1,r);
        tree[i] = tree[i<<1] + tree[(i<<1)|1];
    }
}
ll query(ll s,ll e,ll i,ll l,ll r)
{
    if(max(l,s) > min(r,e))
        return 0;
    else if(s<=l && r<=e)
        return tree[i];
    else
    {
        ll mid = (l+r)>>1;
        return query(s,e,i<<1,l,mid) + query(s,e,(i<<1)|1,mid+1,r);
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
    while(q--)
    {
        ll op;
        cin>>op;
        if(op==1)
        {
            ll i,val;
            cin>>i>>val;
            update(i,val,1,1,n);
        }
        else if(op==2)
        {
            ll l,r;
            cin>>l>>r;
            cout<<query(l,r,1,1,n)<<"\n";
        }
    }
    return 0;
}
