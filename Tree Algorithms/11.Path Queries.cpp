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
/* 
Read more about euler tours and its application and types at:
https://codeforces.com/blog/entry/18369 :- types
https://codeforces.com/blog/entry/63020 :- how to use(It contains one comment at last,read it)
*/
const int MXN = 4e5+781;
ll value[MXN],tin[MXN],tout[MXN];
ll _time=0;
ll arr[MXN],bit[MXN];
ll vis[MXN]{};
vl adj[MXN];
void update(ll i,ll val)
{
    while(i<MXN)
    {
        bit[i]+=val;
        i+=i&-i;
    }
}
ll sum(ll i)
{
    ll ans=0;
    while(i>0)
    {
        ans+=bit[i];
        i-=i&-i;
    }
    return ans;
}
ll sum(ll l,ll r)
{
    return sum(r)-sum(l-1);
}
void dfs(ll src)
{
    if(!vis[src])
    {
        vis[src]=1;
        tin[src]=++_time;
        arr[_time]=src; //euler tour with every node only twice...another variant is used for RMQ
        update(_time,value[src]);  //construct the fenwick tree
        for(auto u:adj[src])
            if(!vis[u])
                dfs(u);
        tout[src]=++_time;
        update(_time,-value[src]);  //this ensures that the subtree which donot appear in path contribute 0
        arr[_time]=src;
    }
}
int main()
{
    IP
    ll n,q;
    cin>>n>>q;
    f(i,0,n)
        cin>>value[i+1];
    f(i,0,n-1)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1);
    while(q--)
    {
        ll op;
        cin>>op;
        if(op==1)
        {
            ll src,val;
            cin>>src>>val;
            update(tin[src],-value[src]);   //remove the old values
            update(tout[src],value[src]);
            update(tin[src],val);           // update the new values
            update(tout[src],-val);
            value[src]=val;
        }
        else
        {
            ll s;
            cin>>s;
            cout<<sum(1,tin[s])<<"\n";
        }
    }
    return 0;
}
