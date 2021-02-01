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
ll par[MXN][50],dis[MXN]{};
bool vis[MXN]{};
void dfs(ll src)
{
    if(!vis[src])
    {
        vis[src]=1;
        for(auto u:adj[src])
            if(!vis[u])
            {
                par[u][0]=src;
                dis[u]=dis[src]+1;
                dfs(u);
            }
    }
}
int main()
{
    IP
    ll n,q;
    cin>>n>>q;
    memset(par,-1,sizeof(par));
    f(i,2,n+1)
    {
        ll x;
        cin>>x;
        adj[i].pb(x);
        adj[x].pb(i);
    }
    dfs(1);
    f(i,1,20)
    {
        f(j,1,n+1)
            if(ll v=par[j][i-1];v!=-1)
                par[j][i]=par[v][i-1];
    }
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        if(dis[a]<dis[b])
            swap(a,b);
        ll diff=dis[a]-dis[b];
        while(diff>0)
        {
            ll up=log2(diff);
            a=par[a][up];
            diff-=1<<up;
        }
        while(par[a][0]!=par[b][0])
        {
            ll k=0;
            while(par[a][k+1]!=par[b][k+1]) //take the maximum leap you can take without passing the LCA
                k++;
            a=par[a][k];    //lift the two nodes by that 2^k distance
            b=par[b][k];
        }
        //after end of this loop they will be just below their LCA
        cout<<(a==b ? a :par[a][0])<<"\n";
    }
    return 0;
}
