#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define int  long long  
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define pb push_back 
#define mp make_pair 
#define ff first 
#define ss second 
#define endl '\n' 
#define sp ' ' 
#define all(v) v.begin() , v.end() 
#define rall(v) v.rbegin() , v.rend() 
#define yes cout << "YES" << endl ;
#define no cout << "NO" << endl ;
#define debg(x) cout << "x : " << x << endl 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii;
typedef map<int, int> mll;
typedef pair<int, int> pii;  
typedef pair<int, bool> pib; 
typedef unsigned int ull; 
typedef long double ld; 
typedef vector<pii> vpii;
typedef vector<pib> vpib;
const int N = 1e5 + 5 ;

void dfs( int v , int p , vi tree[] , vi &leaf , vi &ans , vi &sz )
{
    sz[v] = 1 ;
    for( auto it : tree[v])
    {
        if( it == p )continue;
        dfs( it , v , tree , leaf , ans , sz ) ;
        sz[v] += sz[it] ;
        leaf[v] += leaf[it] ;
    }
    if( sz[v] == 1 )leaf[v] = 1 ;
    ans[sz[v]] = min( ans[sz[v]] , leaf[v]) ;
}
void solve()
{
    int n ;
    cin >> n ;
    vi tree[n+1] ;
    for( int i = 2 ; i <= n ; i++)
    {
        int p;
        cin >> p ;
        tree[p].push_back(i) ;
        tree[i].push_back(p) ;
    }
    vi ans( n + 1 , n+1 ) , sz( n + 1 , 0 ) , leaf(n+1,0) ;
    dfs(1,0,tree,leaf,ans,sz) ;
    for( int i = 1 ; i <= n ; i++ )
    {
        cout << ans[i] << sp ;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    cout << setprecision(20)  << fixed ;
    int t = 1 ; 
    // cin>>t ; 
    while(t-- > 0 )
    {
        solve() ;
    }
    return 0;
}