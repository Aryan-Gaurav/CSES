Problem Link:- https://cses.fi/problemset/task/1202/

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
ll dis[MXN],mx[MXN],mn[MXN],cnt[MXN];
int main()
{
    IP
    ll n,m;
    cin>>n>>m;
    f(i,0,m)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        adj[x].pb({w,y});
    }
    f(i,1,n+1)
        dis[i]=1e18;
    priority_queue<pll,vll,greater<pll> > pq;
    pq.push({0,1});
    dis[1]=0;
    cnt[1]=1;
    while(!pq.empty())
    {
        auto [d,u]=pq.top();
        pq.pop();
        if(dis[u]<d)
            continue;
        for(auto [w,v]:adj[u])
        {
            if(ckmin(dis[v],dis[u]+w))
            {
                 pq.push({dis[v],v});
                 cnt[v]=cnt[u];
                 mx[v]=mx[u]+1;
                 mn[v]=mn[u]+1;
            }
            else if(dis[v] == dis[u]+w)
            {
                // pq.push({dis[v],v}); //this was leading to TLE we donot need this
                /*
                 Lets consider the part of graph in which node x can be reached from a and b.
                 We would propagate the count,min,max to x from a and b.After sometime then x will
                 be popped and will never be updated again.So no need to push x several times.It 
                 would lead to double updation of nodes connected to x

                */

                cnt[v]+=cnt[u];
                if(cnt[v]>=P)
                    cnt[v]-=P;
                ckmax(mx[v],mx[u]+1);
                ckmin(mn[v],mn[u]+1);
            }
        }
    }
    cout<<dis[n]<<" "<<cnt[n]<<" "<<mn[n]<<" "<<mx[n]<<"\n";
    return 0;
}
