//Problem Link :-https://cses.fi/problemset/task/1196/

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
vll adj[MXN];
vl dis[MXN];
int main()
{
    IP
    ll n,m,k;
    cin>>n>>m>>k;
    f(i,0,m)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        adj[x].pb({y,w});
    }
    priority_queue<pll,vll,greater<pll> > pq;   //why we donot use set because set donot allow
                                                //multiple copies of same pair so if there are 2 paths from 1 to u with same weight,it will be checked and updated only once.
                                               //but here we are allowed to give paths of equal weight
    pq.push({0,1});
    while(!pq.empty())
    {
        auto [d,u] = pq.top();
        pq.pop();
        if(sz(dis[u])>=k)
            continue;
        dis[u].pb(d);   //push this current distance to the vector
        for(auto [v,w]:adj[u])
            pq.push({d+w,v});
    }
    for(auto x:dis[n])
        cout<<x<<" ";
    return 0;
}
