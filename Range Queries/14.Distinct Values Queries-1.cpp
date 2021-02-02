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
const int MXN = 2e5+139;
/*
Read more about Mo's algo at
https://cp-algorithms.com/data_structures/sqrt_decomposition.html
https://codeforces.com/blog/entry/81716 :- conatins link to different algos
https://codeforces.com/blog/entry/7383
*/
ll v[MXN],t[MXN],cnt[MXN];
struct range
{
    ll l,r,idx,i;
    bool operator < (range &a) const
    {
        if(idx==a.idx)
            return idx&1 ? r>a.r : r<a.r;   //this is a slight optimisation for even and odd blocks,for more visulaise how right pointer moves when we go from one block to next one
        return idx < a.idx;
    }
};
range query[MXN];
int main()
{
    IP
    ll n,q;
    cin>>n>>q;
    f(i,0,n)
        cin>>t[i],v[i]=t[i];
    sort(t,t+n);
    f(i,0,n)
        v[i]=upper_bound(t,t+n,v[i])-t; //coordinate compression
    const ll siz = 500; //for 2e5 sqrt is approx this
    f(i,0,q)
    {
        auto &[a,b,c,d]=query[i];
        d=i;
        cin>>a>>b;
        a--,b--;
        c=a/siz;    //dividing every time is costly so store it
    }
    sort(query,query+q);
    ll l=0,r=-1,ans=0;
    f(i,0,q)
    {
        auto &[a,b,idx,j]=query[i];
        while(a<l)  //you are forward to left end so come back
        {
            l--;
            cnt[v[l]]++;
            if(cnt[v[l]]==1)
                ans++;
        }
        while(r<b)
        {
            r++;
            cnt[v[r]]++;
            if(cnt[v[r]]==1)
                ans++;
        }
        while(l<a)
        {
            cnt[v[l]]--;
            if(cnt[v[l]]==0)
                ans--;
             l++;   //see the difference when incrementing in case of deletion and addtion of elements
        }
        while(b<r)
        {
            cnt[v[r]]--;
            if(cnt[v[r]]==0)
                ans--;
            r--;
        }
        t[j]=ans;
    }
    f(i,0,q)
        cout<<t[i]<<" ";
    return 0;
}
