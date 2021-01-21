// Problem Link:- https://cses.fi/problemset/task/1691/

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
/*
For euler tour and circuits watch https://www.youtube.com/watch?v=8MpoO2zA2l4&t=308s
*/
ll deg[MXN];
set<ll> adj[MXN];
ll n,m,st=-1,ed=-1;
bool iseuler()
{
    ll cnt=0;
    f(i,1,n+1)
    {    
        if(deg[i]&1)
        {
            cnt++;
            if(st==-1)
                st=i;
            else ed=i;
        }
    }
    if(cnt==2 || cnt==0)
        return 1;
    else return 0;
}
stack<ll> stk;
void dfs(ll src)
{
    while(!adj[src].empty())
    {
        auto u=*adj[src].begin();
        adj[src].erase(adj[src].begin());   //for deleting an edge we want to delete them from 2 lists so searching and deletion must be very efficient
        adj[u].erase(src);
        dfs(u);
    }
    stk.push(src);
}
int main()
{
    IP
    
    cin>>n>>m;
    f(i,0,m)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].insert(y);
        adj[y].insert(x);
        deg[x]++,deg[y]++;
    }
    if(iseuler() && st==-1) //we donot want here paths so st must not be updated
    {
        if(st==-1)  //this is used to update in generic case, when euler circuit exits then we must choose any vertex
            st=1;
        dfs(st);
        if(sz(stk)==m+1)    //We ue here stack but its undirected graph so normally would also work
        {
            while(!stk.empty())
            {
                cout<<stk.top()<<" ";
                stk.pop();
            }
        }
        else cout<<"IMPOSSIBLE\n";
    }
    else cout<<"IMPOSSIBLE\n";
    return 0;
}
/*
Counter Test Case when there are 2 SCC in graphs
4 3

1 4
2 3
3 2
*/
