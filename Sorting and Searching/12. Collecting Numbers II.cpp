#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>    //Read at https://codeforces.com/blog/entry/11080
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/* find_by_order(k):- returns itertator to kth largest element in set (0-based)
   order_of_key(x):- return number of values strictly less than x
*/
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
#define PI acos(-1.0l)
#define mod 998244353
#define pb push_back
#define F first
#define S second
#define IP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fixed(n) cout<<std::fixed<<std::setprecision(n) //use for n digits precision of decimal
/*  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);  */
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
const int MXN = 2e5+381;
ll v[MXN],pos[MXN];
ll n,m;
ll ans=1;
void change(ll i,ll j,ll a)
{
    ll x=v[i],y=v[j];
    if(x>=1 && pos[x-1] > pos[x])
        ans+=a;
    if(x<n-1 && pos[x] > pos[x+1])
        ans+=a;
    if(y==x+1)
    {
        if(y<n-1  && pos[y]>pos[y+1])
            ans+=a;
    }
    else if(y==x-1)
    {
        if(y>=1 && pos[y-1] > pos[y])
            ans+=a;
    }
    else
    {
        if(y>=1 && pos[y-1]>pos[y])
            ans+=a;
        if(y<n-1 && pos[y]>pos[y+1])
            ans+=a;
    }
}
int main()
{
    IP
  
    cin>>n>>m;
    f(i,0,n)
    {
        cin>>v[i];
        pos[--v[i]]=i;
    }
    f(i,0,n-1)
        if(pos[i]>pos[i+1]) //only at these positions your streak will break
            ans++;
    ll a,b;
    while(m--)
    {
        cin>>a>>b;
        a--,b--;
        change(a,b,-1);
        swap(pos[v[a]],pos[v[b]]);
        swap(v[a],v[b]);
        change(a,b,1);
        cout<<ans<<"\n";
    }
    return 0;
}
