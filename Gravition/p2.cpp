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
const int N = 2e5 + 5; 
const int inf = 1e14 + 5  ; 
int dp[1005][1005][2] ;
int solution( vector<vector<int>> &cost , int n  , int sx , int sy , int ex , int ey  )
{
     for( int i = 0 ; i < 1005 ; i++ )for( int j = 0 ; j < 1005 ;j++ )dp[i][j][0] = inf , dp[i][j][1] = inf  ;
     if( ey > sy )
     {
         dp[sy][sx][0] = cost[sy][sx] ;
         dp[sy][sx][1] = cost[sy][sx] ;
         for( int i = sy ; i <= ey ; i++ )
         {
            for( int j = sx ; j <= ex ; j++  )
            {
                if( i == sy && j == sx )continue;
                dp[i][j][0] = min( dp[i][j-1][0] - cost[i][j-1] ,  dp[i][j-1][1] ) +  cost[i][j] ;  
                dp[i][j][1] = min( dp[i-1][j][1] - cost[i-1][j] ,  dp[i-1][j][0] ) +  cost[i][j] ;  
            }
         }
         return min( dp[ey][ex][0] , dp[ey][ex][1] ) + cost[sy][sx];
     }
     else 
     {
         dp[sy][sx][0] = cost[sy][sx] ;
         dp[sy][sx][1] = cost[sy][sx] ;
        for( int i = sy ; i >= ey ; i-- )
         {
            for( int j = sx ; j <= ex ; j++  )
            {
                if( i == sy && j == sx )continue;
                dp[i][j][0] = min( dp[i][j-1][0] - cost[i][j-1] ,  dp[i][j-1][1] ) +  cost[i][j] ;  
                dp[i][j][1] = min( dp[i+1][j][1] - cost[i+1][j] ,  dp[i+1][j][0] ) +  cost[i][j] ;  
            }
         }
         return min( dp[ey][ex][0] , dp[ey][ex][1] ) + cost[sy][sx];
     }
}
void solve() 
{
    int n ; 
    cin>> n ;
    vector<vector<int>> cost( n + 5 , vector<int>( n + 5 , 0 )) ;
    int sx  , sy , ex , ey ;
    cin>>sy>>sx>>ey>>ex ; 
    f( i , 0 , n )f( j , 0 , n )cin>>cost[i+1][j+1] ; 
    if( sx <= ex )cout<<solution( cost , n , sx , sy , ex , ey  ) << endl ;
    else cout<<solution( cost , n , ex , ey , sx , sy  ) << endl ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        solve();
    }
    return 0;
}