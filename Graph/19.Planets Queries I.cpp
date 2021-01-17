// Probelem Link:- https://cses.fi/problemset/task/1750/

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
const int MXN=2e5+651;
ll nxt[MXN][31];
int main()
{
    IP
    ll n,q;
    cin>>n>>q;
    ll x;
    f(i,1,n+1)
    	cin>>nxt[i][0];
    f(j,1,31) //idea is very much similar to binary lifting to find LCA in a tree
    	f(i,1,n+1)
        if(ll x=nxt[i][j-1];x!=0)
          nxt[i][j]=nxt[x][j-1];
    while(q--)
    {
    	ll x,k;
    	cin>>x>>k;
    	while(k>0 && x!=0)
    	{
    		ll up=log2(k);
    		x=nxt[x][up];
    		k-=1<<up;
    	}
    	cout<<x<<"\n";
    }
    return 0;
}
