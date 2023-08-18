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

void dfs( int v , vvi  &dp , vi graph[], vb &vis)
{
    vis[v] = true ;
    dp[v][0] = 1 ;
    dp[v][1] = 1 ;

    for( auto it : graph[v])
    {
        if( vis[it] )continue;
        dfs(it , dp , graph , vis  ) ;
        dp[v][0] *= dp[it][1] ;
        dp[v][0] %= mod ; 
        dp[v][1] *= (dp[it][1] + dp[it][0]) ;
        dp[v][1] %= mod ; 
    }
}

void solve()
{
    int n ;
    cin >> n ;
    vvi dp( n+1 , vi( 2 , 0 )) ;
    vb vis( n + 1 , false ) ;
    vi graph[n+1] ;
    for( int i = 0 ; i < n-1 ; i++)
    {
        int u , v ;
        cin >> u >> v ;
        graph[u].push_back(v) ;
        graph[v].push_back(u) ;
    }
    dfs(1,dp,graph,vis) ;
    cout << (dp[1][0] + dp[1][1]) % mod << endl ;
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