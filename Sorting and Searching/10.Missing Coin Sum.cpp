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
ll v[MXN],pre[MXN];
/*
Read more at https://medium.com/dexters-lab/eli5-find-the-smallest-positive-integer-value-that-cannot-be-represented-as-sum-of-any-subset-of-f8ea2488184b
*/
int main()
{
    IP
    ll n;
    cin>>n;
    f(i,0,n)
        cin>>v[i];
    sort(v,v+n);
    ll ans=0;
    f(i,0,n)
    {
        if(v[i] <= ans+1)   //we can create continuous series till ans+v[i] using v[i]
            ans+=v[i];
        else break;
    }
    ans++;
    cout<<ans;
    return 0;
}
/*
Let the array be A=[1,1,1,2,7]
so we mark in step 
1> we mark 1
2> we mark 1 and 2
3> we marks 1,2,3
4> we mark 1,2,3,4,5
5> when we encounter 7 we can't from 6 which forms a gap.
In each step we add a[i] to each of previous formed values and mark them as done.
When we have current_element just next to sum of all elements till (i-1),then also we are safe, but as soon
as we are 2 more than sum,then notice  we can't form sum+1,with any combinations.We try to find that
gap.
*/
