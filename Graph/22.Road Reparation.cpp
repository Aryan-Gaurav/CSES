// Problem Link:- https://cses.fi/problemset/task/1675/

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
const int MXN = 2e5+781;
ll par[MXN],siz[MXN];
ll findpar(ll x)
{
    if(par[x]==x)
        return x;
    par[x]=findpar(par[x]); //path compression
    return par[x];
}
bool isame(ll x,ll y)
{
    return findpar(x)==findpar(y);
}
void join(ll x,ll y)
{
    ll p1=findpar(x),p2=findpar(y);
    if(p1==p2)
        return;
    if(siz[p1]>=siz[p2])
    {
        siz[p1]+=siz[p2];
        par[p2]=p1;
    }
    else join(y,x);
}
int main()
{
    IP
    ll n,m; //This is classical Krushkal implentation
    cin>>n>>m;
    f(i,1,n+1)
        par[i]=i,siz[i]=1;
    set<ar<ll,3>> st;
    f(i,0,m)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        st.insert({w,u,v});
    }
    ll cnt=0,ans=0;
    while(!st.empty())
    {
        auto [w,u,v]=*st.begin();
        st.erase(st.begin());
        if(!isame(u,v) && cnt<n-1)
        {
            cnt++;
            join(u,v);
            ans+=w;
        }
    }
    if(cnt!=n-1)
        cout<<"IMPOSSIBLE\n";
    else cout<<ans;
    return 0;
}
