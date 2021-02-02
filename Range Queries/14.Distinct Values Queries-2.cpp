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
ll v[MXN],t[MXN],bit[MXN],pos[MXN];
void update(ll i,ll val)
{
    while(i<MXN)
    {
        bit[i]+=val;
        i+=i & -i;
    }
}
ll sum(ll i)
{
    ll ans=0;
    while(i>0)
    {
        ans+=bit[i];
        i-=i & -i;
    }
    return ans;
}
ll sum(ll l,ll r)
{
    return sum(r)-sum(l-1);
}
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
    vector<ar<ll,3> > query(q);
    f(i,0,q)
    {
        auto &[r,l,j]=query[i];
        cin>>l>>r;
        j=i;
    }
    sort(all(query));   //sort all queries according to their increasing right end
    memset(pos,-1,sizeof(pos)); //previous positions of every element
    ll curr=0;
    /*
    When we encounter an element we erase 1 from its old position and mark 1 at new position
    we have already sorted the ranges so it would not alter any answer of other queries
    */
    f(i,0,n)
    {
        if(pos[v[i]]!=-1)
            update(pos[v[i]],-1);   //remove 1 from old position
        update(i+1,1);          //add 1 to current position
        pos[v[i]]=i+1;
        while(curr<q && query[curr][0]==i+1)
        {
            auto &[r,l,j]=query[curr];
            t[j]=sum(l,r);
            curr++;
        }
    }
    f(i,0,q)
        cout<<t[i]<<" ";
    return 0;
}
