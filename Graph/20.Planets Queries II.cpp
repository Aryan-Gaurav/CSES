//Problem Link:- https://cses.fi/problemset/task/1160/

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
ll nxt[MXN][20],dis[MXN];
bool vis[MXN];
void dfs(ll src)
{
    if(!vis[src])
    {
        vis[src]=1;
        dfs(nxt[src][0]);
        dis[src]=dis[nxt[src][0]]+1;
    }
}
ll lift(ll x,ll d)
{
    while(d>0)
    {
        ll up=log2(d);
        x=nxt[x][up];
        d-=1<<up;
    }
    return x;
}
int main()
{
    IP
    ll n,q;
    cin>>n>>q;
    f(i,1,n+1)
        cin>>nxt[i][0];
    f(j,1,20)
        f(i,1,n+1)
            if(ll x=nxt[i][j-1];x!=0)
                nxt[i][j]=nxt[x][j-1];
    f(i,1,n+1)
        if(!vis[i])
            dfs(i);
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        ll par=lift(a,dis[a]);  //we reach the satrt of cycle
        /*
        Remember we have to find path between a to b.
        2 cases arise, b is infront of a OR b is in cycle and a is in st. line part
        */
        if(lift(a,dis[a]-dis[b])==b)
            cout<<dis[a]-dis[b]<<"\n";
        else if(lift(par,dis[par]-dis[b])==b)
            cout<<dis[a]+(dis[par]-dis[b])<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}
