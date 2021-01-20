//Problem Link:- https://cses.fi/problemset/task/1686/

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
const int MXN = 2e5+381;
vl adj[MXN],radj[MXN];
bool vis[MXN]{};
stack<ll> stk;
ll who[MXN],coin[MXN],total[MXN];
void dfs(ll src)
{
    if(!vis[src])
    {
        vis[src]=1;
        for(auto u:adj[src])
            if(!vis[u])
                dfs(u);
        stk.push(src);
    }
}
vl scc;
void dfs1(ll src)
{
    if(!vis[src])
    {
        vis[src]=1;
        total[who[src]]+=coin[src];
        scc.pb(src);
        for(auto u:radj[src])
            if(!vis[u])
            {
                who[u]=who[src];
                dfs1(u);
            }
    }
}
vl dag[MXN];
ll dp[MXN];
void dfs2(ll src)
{
    if(vis[src])
        return;

    vis[src]=1;
    for(auto u:dag[src])
        dfs2(u);
    stk.push(src);
}
int main()
{
    IP
    ll n,m;
    cin>>n>>m;
    f(i,1,n+1)
        cin>>coin[i];
    f(i,0,m)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        radj[b].pb(a);
    }
    f(i,1,n+1)
        if(!vis[i])
            dfs(i);
    clr(vis);
    ll cnt=0;
    vector<vl> allcomp;
    while(!stk.empty())
    {
        ll u=stk.top();
        stk.pop();
        if(!vis[u])
        {
            scc.clear();
            who[u]=++cnt;
            dfs1(u);
            allcomp.pb(scc);
        }
    }
    clr(vis);
    //construct the DAG of SCC's
    f(i,1,n+1)
        for(auto u:adj[i])
            if(who[u]!=who[i])
                dag[who[i]].pb(who[u]);
    f(i,1,cnt+1)
    {
        sort(all(dag[i]));
        dag[i].erase(unique(all(dag[i])),dag[i].end()); //remove repeated elements in dag adjacency list,although not req
    }
    f(i,1,cnt+1)
        if(!vis[i])
            dfs2(i);
        //In DAG its very easy to update the longest or sortest path in topological order
    while(!stk.empty()) //this is topological sort of DAG of SCC
    {
        ll u=stk.top();
        stk.pop();
        dp[u]+=total[u];
        for(auto v:dag[u])
            ckmax(dp[v],dp[u]); //try to update next nodes to take maximum out of all incoming edges
    }
    cout<<*max_element(dp+1,dp+cnt+1);
    return 0;
}
