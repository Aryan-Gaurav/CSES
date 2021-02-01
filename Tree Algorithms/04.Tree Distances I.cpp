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
const int MXN = 2e5+176;
vl adj[MXN];
ll dis[MXN][2];
void dfs(ll src,ll idx,ll par=-1)
{
    for(auto u:adj[src])
    {
        if(u!=par)
        {
            dis[u][idx]=dis[src][idx]+1;
            dfs(u,idx,src);
        }
    }
}
int main()
{
    IP
    ll n;
    cin>>n;
    f(i,0,n-1)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0);
    ll u=-1,val=0;
    f(i,1,n+1)
        if(val<dis[i][0])
        {
            val=dis[i][0];
            u=i;
        }
    dis[u][0]=0;
    dfs(u,0);
    u=-1,val=0;
    f(i,1,n+1)
        if(val<dis[i][0])
        {
            val=dis[i][0];
            u=i;
        }
    dfs(u,1);
    f(i,1,n+1)
        cout<<*max_element(dis[i],dis[i]+2)<<" ";
    return 0;
}
