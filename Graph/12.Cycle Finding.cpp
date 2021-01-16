//Probelm Link:- https://cses.fi/problemset/task/1197/


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
const int MXN = 5e3+781;
tuple<ll,ll,ll> edge[MXN];
vector<ll> dis(3500,1e18);
ll par[MXN];
bool vis[MXN]{};
vl adj[MXN];
void dfs(ll src)
{
    if(!vis[src])
    {
        vis[src]=1;
        for(auto v:adj[src])
            if(!vis[v])
                dfs(v);
    }
}
int main()
{
    IP
    ll n,m;
    cin>>n>>m;
    f(i,0,m)
    {
        auto &[u,v,w]=edge[i];
        cin>>u>>v>>w;
        adj[u].pb(v);
    }
    ll x=-1;
    bool isneg=0;
    f(i,1,n+1)
    {
        if(!vis[i])
        {
            dfs(i); //this is done so that we can run bellman for disconnected parts of graph
            dis[i]=0;
        }
    }
    f(i,0,n)
    {
        bool change=0;
        f(j,0,m)
        {
           auto [u,v,w]=edge[j];
           if(dis[u]!=1e18)
               if(ckmin(dis[v],dis[u]+w))
               {
                change=1;
                par[v]=u;
                if(i==n-1)
                    x=v,isneg=1;
               } 
        }
        if(!change)
            break;
    }
    if(!isneg)
        cout<<"NO\n";
    else
    {
        vl v;
        f(i,0,n)
            x=par[x];
        v.pb(x);
        for(ll y=par[x];y!=x;y=par[y])
            v.pb(y);
        v.pb(x);
        reverse(all(v));
        cout<<"YES\n";
        for(auto x:v)
            cout<<x<<" ";
    }
    return 0;
}
