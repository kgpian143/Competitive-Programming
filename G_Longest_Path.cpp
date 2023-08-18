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
typedef vector<vector<int>> vvl; 
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
vi graph[N] ;
int dp[N] ;

void dfs( int v )
{
    if( dp[v] > 0 )return ;

    for( auto it : graph[v])
    {
        dfs(it) ;
        dp[v] = max( dp[v] , dp[it] + 1);
    }
}
void solve()
{
    int n , m ;
    cin >> n >> m ; 
    for( int i = 0 ; i < m ; i++)
    {
        int u , v ;
        cin >> u >> v ;
        graph[u].push_back(v);
    }
    int ans = 0 ;
    for( int i = 1 ; i <= n ; i++)
    {
        if( dp[i] == 0 )dfs(i) ;
        ans = max(ans , dp[i]) ;
    }
    cout << ans << endl;
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t = 1 ; 
    // cin>>t ; 
    while(t-- > 0 )
    {
        solve() ;
    }
    return 0;
}