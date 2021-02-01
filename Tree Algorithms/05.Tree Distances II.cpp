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
#define PI 3.141592653589793238462643383279502884197169399L
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
const int MXN = 2e5+781;
vl adj[MXN];
ll cnt[MXN],lower[MXN],dp[MXN],up[MXN];
ll n;
void dfs(ll src,ll par=-1)
{
    cnt[src]=1;
    for(auto u:adj[src])
    {
        if(u!=par)
        {
            dfs(u,src);
            cnt[src]+=cnt[u];
            lower[src]+=cnt[u]+lower[u];
        }
    }
}
void update(ll src,ll par=-1)
{
    for(auto u:adj[src])
    {
        if(u!=par)
        {
            dp[u]=dp[src]+(n-cnt[u])-cnt[u]; // overall result increases by n-cnt[u] and decreases by cnt[u]
            update(u,src);                   // this happens as we go down the distance of all nodes in subtree is decreased by 1 so its contri
                                            // is -1 per node and remaning nodes distance increases by 1
        }
    }
}
int main()
{
    IP
    cin>>n;
    f(i,0,n-1)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1);
    dp[1]=lower[1];
    update(1);
    f(i,1,n+1)
        cout<<dp[i]<<" ";
    return 0;
}
