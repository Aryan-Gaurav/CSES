#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>    //Read at https://codeforces.com/blog/entry/11080
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/* 
find_by_order(k):- returns itertator to kth largest element in set (0-based)
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
#define PI acosl(-1.0l)
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
ll v[MXN],loog[MXN];
/*
Read about sparse tables at https://cp-algorithms.com/data_structures/sparse-table.html
RMQ in O(1).Drawback is static.
*/
ll table[MXN][20];
int main()
{
    IP
    ll n,q;
    cin>>n>>q;
    f(i,0,n)
        cin>>v[i];
    loog[1]=0;
    f(i,2,MXN)
        loog[i]=loog[i/2]+1; //value of floor(log(i))
    f(i,0,n)
        table[i][0]=v[i];
    f(j,1,20)
        f(i,0,n)                    //                   |--> minimum here is added so index may pass the limits and cause RTE
            table[i][j]=min(table[i][j-1],table[min(i+(1<<(j-1)),n-1)][j-1]);
    ll l,r,k;
    while(q--)
    {
        cin>>l>>r;
        l--,r--;
        k=loog[r-l+1];
        cout<<min(table[l][k],table[r-(1<<k)+ 1][k])<<"\n";//this is beauty of RMQ the min of [l,r]=min([l,l+2^k],[r-2^k+1,r]) as overalapping elements pose no problem
    }
    return 0;
}
