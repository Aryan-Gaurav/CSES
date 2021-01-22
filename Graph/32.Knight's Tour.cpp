//Problem Link:- https://cses.fi/problemset/task/1689/


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
Read about Warnsdorff algorithm which suggests to go to next node in graph which has least degree.
This can be generally applied in normal Graph problems too.
For more about tie-breaking rules read https://stackoverflow.com/a/24738975/13543838 
It suggests 2 methods to break ties,either follow a fixed combination of n numbers or take the point with
largest euclidean distance from center of board.This can be used to solve for n<=2000 which is huge.
*/
int ddx[]={-1,-1,-2,-2, 1, 1, 2, 2};
int ddy[]={-2, 2, 1,-1,-2, 2, 1,-1};
ll cnt[8][8],ans[8][8];
bool vis[8][8];
vll adj[8][8];
ll dis(ll x,ll y,ll n) //calculates euclidean distance from center of n*n board
{
 return (n/2-x)*(n/2-x)+(n/2-y)*(n/2-y);   
}
struct cmp
{
    bool operator() (const ar<ll,3> &a,const ar<ll,3> &b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        return dis(a[1],a[2],8) > dis(b[1],b[2],8);
    }
};
bool backtrack(ll total,ll x,ll y)
{
    if(total==64)
    {
        ans[x][y]=total;
        return 1;
    }
    vis[x][y]=1;
    ans[x][y]=total;
    
    ll val=-1,ax,bx;
    set<ar<ll,3>,cmp> st; //normal sorting would also give results because you break ties by normal order (1,2....n)
    for(auto [a,b]:adj[x][y])
        if(!vis[a][b])
        {
            cnt[a][b]--;
            st.insert({cnt[a][b],a,b});
        }
    while(!st.empty())
    {
        auto [c,xx,yy]=*st.begin();
        st.erase(st.begin());
        if(backtrack(total+1,xx,yy))
            return 1;
    }
    for(auto [a,b]:adj[x][y])   //if solution is not found then reset the counts
        if(!vis[a][b])
        {
            cnt[a][b]++;
        }
    vis[x][y]=0;    //mark current node as not visited
    return 0;
}
int main()
{
    IP
    f(i,0,8)
        f(j,0,8)
            f(k,0,8)
            {
                int nx=i+ddx[k],ny=j+ddy[k];
                if(nx<0||nx>=8||ny<0||ny>=8)
                    continue;
                adj[i][j].pb({nx,ny});
                cnt[i][j]++;
            }
    int x,y;
    cin>>y>>x;
    x--,y--;
    backtrack(1,x,y);
    f(i,0,8)
    {
        f(j,0,8)
        cout<<ans[i][j]<<" ";cout<<"\n";
    }
    return 0;
}
