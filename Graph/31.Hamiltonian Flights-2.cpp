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
Watch tutorial of TSP at https://www.youtube.com/watch?v=cY4HiiFHO1o&t=1094s
Read more about Dp over subsets at https://codeforces.com/blog/entry/337
*/
int adj[20][20]{};
ll dp[1<<20][20];
int main()
{
    IP
    int n,m,a,b;
    cin>>n>>m;
    f(i,0,m)
    {
        cin>>a>>b;
        a--,b--;
        adj[a][b]++;
    }
    dp[1][0]=1;
    //This version of DP is push-up DP i.e. we push the values from current state to next state
    for(int mask=1;mask<1<<n;mask++)    //No need to generate separately the masks,just iterate normally till 2^n,every thing will be taken care of.
    {
        for(int i=0;i<n-1;i++)                   //     |-->> This optimistaion changed from TLE to AC
        {                                         //    |
            if(mask & (1<<i) && dp[mask][i] && ! (mask &(1<<(n-1))))   //check if i is visited in current mask and n must be unvisited till now so we will update
            {
                for(int j=0;j<n;j++)
                {
                    if(mask&(1<<j)||adj[i][j]==0) //donot update if j is already visited in mask or when there is no path from i to j
                        continue;
                    int newmask=mask|1<<j;  //Calculate the next state from current state
                    dp[newmask][j]+=(adj[i][j]*dp[mask][i])%P;
                    if(dp[newmask][j]>=P)   //avoid modulo operator
                        dp[newmask][j]-=P;
                }
            }
        }
    }
    cout<<dp[(1<<n)-1][n-1];
    return 0;
}
