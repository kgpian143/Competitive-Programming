#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define int  long long  
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<int> vl;
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii;
typedef map<int, int> mll;
typedef pair<int, int> pii;  
typedef pair<int, bool> pib; 
typedef pair<int, int> pll; 
typedef unsigned int ull; 
typedef long double ld; 
typedef int ll; 
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;
const int N = 1e5 + 5 ;

void dfs( int v , int p , vi tree[] , int depth , vector<double> &dp ,  double &ans )
{
    bool isleaf = true ;
    for( auto it : tree[v] )
    {
        if( it == p )continue;
        isleaf = false ;
        if( v == 1 )
        {
            dp[it] = dp[v] / tree[v].size() ;
        }
        else 
        {
            dp[it] = dp[v] / (tree[v].size() - 1) ;
        }
        dfs( it , v , tree , depth + 1 , dp , ans ) ;
    }
    if( isleaf )
    {
        ans += depth * dp[v] ;
    }
}
void solve()
{
    int n ;
    cin >> n ;
    vi tree[n+1] ;
    for( int i = 1 ; i < n ; i++)
    {
        int u , v ;
        cin >> u >> v ;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    vector< double > dp( n + 1 , 0 ) ; 
    dp[1] = 1 ;
    double ans = 0 ;
    dfs( 1 , 0 , tree , 0 , dp , ans ) ; 
    cout << setprecision(20) << fixed ;
    cout << ans << "\n" ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t = 1; 
    // cin>>t ; 
    while(t-- > 0 )
    {
        solve() ;
    }
    return 0;
}