//Problem Link:- https://cses.fi/problemset/task/1682/


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
stack<ll> stk;
bool vis[MXN]{};
void dfs(ll src)
{
    if(!vis[src])
    {
        vis[src]=1;
        for(auto u:adj[src])
            if(!vis[u])
                dfs(u);
    }
}
void dfs1(ll src)
{
    if(!vis[src])
    {
        vis[src]=1;
        for(auto u:radj[src])
            if(!vis[u])
                dfs1(u);
    }
}
int main()
{
    IP
    ll n,m;
    cin>>n>>m;
    f(i,0,m)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        radj[y].pb(x);
    }
    dfs(1);
    bool found=0;
    f(i,1,n+1 && !found)
        if(!vis[i])
            cout<<"NO\n1 "<<i<<"\n",found=1;
    clr(vis);
    dfs1(1);    // this marks all the nodes from which 1 can be reached
    f(i,1,n+1 && !found)
        if(!vis[i])
            cout<<"NO\n"<<i<<" 1\n",found=1;
    if(!found)
        cout<<"YES\n";
    /*
    Proof of this method by contradiction,if we donot have a path between u and v and this method 
    donot detect any pair then you can go from u to 1 and then 1 to v.So we can say every pair has
    path between them.
    */
    return 0;
}
