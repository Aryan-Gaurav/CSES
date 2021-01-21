//Problem Link:- https://cses.fi/problemset/task/1693/


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
ll in[MXN],out[MXN];
vl adj[MXN];
ll n,m,st=-1,ed=-1;
bool iseuler()
{
    ll cnt1=0,cnt2=0;
    f(i,1,n+1)
    {
        if(in[i]!=out[i])
        {
            if(in[i]-out[i]==1)
                cnt1++,ed=i;
            else if(out[i]-in[i]==1)
                cnt2++,st=i;
            else return 0;
        }
    }
    if(cnt1<=1 && cnt1==cnt2)
        return 1;
    return 0;
}
stack<ll> stk;
void dfs(ll src)
{
    while(!adj[src].empty())
    {
        ll u=adj[src].back();
        adj[src].pop_back();
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
        adj[x].pb(y);
        out[x]++;
        in[y]++;
    }
    if(iseuler())
    {
        if(st==-1)  //this is used to update in generic case, when euler circuit exits then we must choose any vertex
            st=1;
        dfs(st);
        if(sz(stk)!=m+1||st!=1||ed!=n)  //this is used to ensure that all edges are removed
            cout<<"IMPOSSIBLE\n";       //here its given that its should start from 1 and end at n so cross check it,in some cases we may get euler circuit
        else
        {
            while(!stk.empty())
            {
                ll t=stk.top();
                stk.pop();
                cout<<t<<" ";
            }
        }
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
