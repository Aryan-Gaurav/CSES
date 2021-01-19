//Problem Link:- https://cses.fi/problemset/task/1751/

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
ll nxt[MXN],dis[MXN],par[MXN],cyclen[MXN],st[MXN];
int vis[MXN];
bool vis1[MXN];
vl radj[MXN];
vl cyc;
void dfs(ll src)
{
    if(!vis[src])
    {
        vis[src]=1;
        if(!vis[nxt[src]])
            dfs(nxt[src]);
        else if(vis[nxt[src]]==1)
        {
            ll u=nxt[src];
            while(u^src)
            {
                cyc.pb(u);
                u=nxt[u];
            }
            cyc.pb(src);
        }
        vis[src]=2;
    }
}
void dfs1(ll src)
{
    if(!vis1[src])
    {
        vis1[src]=1;
        for(auto u:radj[src])
        {
            if(!vis1[u])
            {
                dis[u]=dis[src]+1;
                st[u]=st[src];
                dfs1(u);
            }
        }
    }
}
int main()
{
    IP
    ll n;
    cin>>n;
    f(i,1,n+1)
    {
        cin>>nxt[i];
        radj[nxt[i]].pb(i); //constructing the reverse graph
    }
    f(i,1,n+1)
    {
        if(!vis[i])
        {
            dfs(i);
            for(auto x:cyc) //if cycle can be reached from current node i then cyc will be filled
            {
                cyclen[x]=sz(cyc);  //update the cycle length for each node in the cycle
                vis1[x]=1;          //for 2nd dfs just mark them as visited
                st[x]=x;            //update starting point in cycle of each of them as itself
            }
            for(auto x:cyc)
            {
                vis1[x]=0;          //just mark the current node as not visited and run dfs from it
                dfs1(x);            //in reverse graph and the distance of the tree from that node will be updated
            }
            cyc.clear();
        }
    }
    f(i,1,n+1)
        cout<<dis[i]+cyclen[st[i]]<<" ";//distance to reach the node starting node of cycle and then length of cycle
    return 0;
}
