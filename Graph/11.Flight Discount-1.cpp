//Problem Link: https://cses.fi/problemset/result/1544306/
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
const int MXN = 1e5+781;
vector<pll>  adj[MXN],radj[MXN];
vector<ll> dis1(MXN,1e18),dis2(MXN,1e18);
bool vis[MXN];
int main()
{
    IP
    ll n,m;
    cin>>n>>m;
    f(i,0,m)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        radj[v].pb({u,w});
    }
    dis1[1]=0;
    set<pll> st;
    st.insert({0,1});
    while(!st.empty())
    {
        auto [d,u]=*st.begin();
        st.erase(st.begin());
        if(dis1[u]<d)    //no use of vis in dijkstra as this also works,this means we have updated the value of u already
            continue;
        for(auto [v,w]:adj[u])
        {
            if(ckmin(dis1[v],dis1[u]+w))
                st.insert({dis1[v],v}); //this calculates shortest path from 1 to every other node
        }
    }
    dis2[n]=0;
    st.insert({0,n});
    while(!st.empty())
    {
        auto [d,u]=*st.begin();
        st.erase(st.begin());
        if(dis2[u]<d)
            continue;
        for(auto [v,w]:radj[u]) //this calulates shortest path from all nodes to n
        {
            if(ckmin(dis2[v],dis2[u]+w))
                st.insert({dis2[v],v});
        }
    }
    // Now consider each edge once and apply discount on that node
    ll ans=1e18;
    f(i,1,n+1)
    {
        for(auto [u,w]:adj[i])
            ckmin(ans,dis1[i]+w/2+dis2[u]);
    } 
    cout<<min(ans,dis1[n]);
    return 0;
}
