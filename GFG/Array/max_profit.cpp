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

int solve()  
{
    int dp[205][505] ;
    int n , k ;
    cin>>n>>k ;
    int price[n+1] ;
    f( i , 0 , n )cin>>price[i] ;
    for( int i = 0 ; i <= n ; i++ )dp[0][i] = 0 ;
    for( int i = 0 ; i <= k ; i++ )dp[k][0] = 0 ;
    for( int i = 1 ; i <= k ; i++ )
    {
        int diff = INT_MIN ;
        for( int j = 1 ; j < n ; j++ )
        {
            diff = max( diff  ,dp[i-1][j-1] - price[j-1]) ;
            dp[i][j] = max( dp[i][j-1] , price[j] + diff );   
        }
    }
    return dp[k][n-1] ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        cout<<solve();
    }
    return 0;
}