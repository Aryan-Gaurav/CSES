//Problem Link : https://cses.fi/problemset/task/1195/
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
struct node
{
    ll u,w,i;
};
vector<node>  adj[MXN][2];
ll dis[MXN][2];
bool vis[MXN][2]{};
int main()
{
    IP
    ll n,m;
    cin>>n>>m;
    f(i,0,m)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u][0].pb(node({v,w,0}));    //create 2 copies of the same graph one is 0th layer
        adj[u][1].pb(node({v,w,1}));    //other is 1st layer.Now connect the 0th layer to 1st
        adj[u][0].pb(node({v,w/2,1}));  //by half weight edges from u[0] to v[1].
    }
    f(i,1,n+1)
        f(j,0,2)
            dis[i][j]=1e18;
    set<tuple<ll,ll,ll> > st;
    st.insert({0,1,0});
    dis[1][0]=0;
    while(!st.empty())
    {
        auto [d,u,i] = *st.begin();
        st.erase(st.begin());
        if(!vis[u][i])
        {
            vis[u][i]=1;
            for(auto [v,w,j]:adj[u][i])
            {
                if(ckmin(dis[v][j],dis[u][i]+w))
                    st.insert({dis[v][j],v,j});
 
            }
        }
    }
    cout<<dis[n][1];
    return 0;
}
