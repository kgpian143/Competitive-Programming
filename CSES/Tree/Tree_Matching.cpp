#include<bits/stdc++.h>
using namespace std ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long 
typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef pair<int, int> pii;  
typedef pair<int, bool> pib;  
typedef unsigned long long ull; 
typedef long double ld; 
typedef vector<pii> vpii; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
#define getv(v,n) for( int i = 0 ; i < n ; i++)cin>>v[i];
#define putv(v) for(auto it : v )cout<<it<<' ';
#define getvv(v,n,m)for(int i = 0 ; i < n ; i++ )f(j,0 ,m)cin>>v[i][j] 
const int N = 2e5 + 5; 
int n ;
vi  g[N] ;
// int par[N] ;
bool vis[N] ;
int dp[N][2] ;
void dfs( int v , int par )
{
    // vis[v] = true  ;
    cout<<v<<" ";
    bool leaf = true  ;
    for( auto it : g[v] )
    {
        if( it == par )continue;
        leaf = false ;
        dfs(it , v) ;
    }
    int sz = g[v].size() ;
    if(leaf)return ;
    // cout<<1;
    vi pref( sz + 2  , 0 ) ;
    int i1 = 1 , j = sz ;
    for( auto it : g[v])
    {
        // if( vis[it])continue;
        if( it == par )continue;
        pref[i1] = pref[i1-1] + max( dp[it][0] , dp[it][1] ) ;
        i1++ ;
    }
    dp[v][0] = pref[sz] ;
    int ans = 0;
    for( int i = 0 ; i < g[v].size() ; i++ )
    {
        if(g[v][i] == par )continue; 
        int ans1 = pref[i] + pref[sz] - pref[i+1] + dp[g[v][i]][0] + 1 ;
        ans = max( ans1  ,  ans ) ;
    }
    dp[v][1] = ans  ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t = 1 ;
    // cin>>t ;
    while(t-- > 0 )
    {
        // solve();
        cin>>n ;
        f( i , 0 , n -1 )
        {
            int u ,  v ;
            cin>>u>>v ;
            g[u].push_back(v) ;
            g[v].push_back(u) ;
            // par[v] = u ;
        }
        dfs(1 , 1);
        for( int i = 1 ; i <=  n ; i++ )cout<<max( dp[i][0] , dp[i][1] )<<endl;
    }
    return 0;
}