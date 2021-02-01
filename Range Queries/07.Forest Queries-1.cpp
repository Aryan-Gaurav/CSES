#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>    //Read at https://codeforces.com/blog/entry/11080
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
 
// template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
const int MXN = 1e3+381;
ll bit[MXN][MXN],v[MXN][MXN];
/*
Read more about 2d fenwick trees at https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees/
Very good to apply thaat concept,but can also be done by simple DP
*/
void update(ll i,ll j,ll val)
{
    while(i<MXN)
    {
        ll t=j;
        while(t<MXN)
        {
            bit[i][t]+=val;
            t+=t & -t;
        }
        i+=i & -i;
    }
}
ll sum(ll i,ll j)
{
    ll ans=0;
    while(i>0)
    {
        ll t=j;
        while(t>0)
        {
            ans+=bit[i][t];
            t-=t & -t;
        }
        i-=i&-i;
    }
    return ans;
}
ll sum(ll ui,ll uj,ll li,ll lj)
{
    return sum(li,lj) - sum(ui-1,lj) - sum(li,uj-1) + sum(ui-1,uj-1);
}
int main()
{
    IP
    ll n,q;
    cin>>n>>q;
    char ch;
    f(i,1,n+1)
        f(j,1,n+1)
        {
            cin>>ch;
            v[i][j]=(ch=='*');
            if(v[i][j])
                update(i,j,1);
        }
    ll li,lj,ui,uj;
    while(q--)
    {
        cin>>ui>>uj>>li>>lj;
        cout<<sum(ui,uj,li,lj)<<'\n';
    }
    return 0;
}
