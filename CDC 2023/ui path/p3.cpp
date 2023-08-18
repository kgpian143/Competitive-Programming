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

int solve( vector<vector<int>> pr , int k)
{
    int n = pr.size() ;
    int m = pr[0].size() ;

    vector<vector<int>> dp( n + 1 , vector<int> ( m+1 , 0)) ;

    for( int i = 1 ; i <= m ; i++ )
    {
        for( int j = 1 ; j <=n ; j++ )
        {
            for( int l = max( 1 * 1LL , j - k  ) ; l <= min( n , j+k ) ; l++ )
            {
                dp[j][i] = max( dp[j][i] , dp[l][i-1] + pr[j-1][i-1]) ;
            }
        }
    }
    int ans = 0 ;
    for( int i = 1 ; i <= n ; i++ )
    {
        ans = max( ans , dp[i][m]) ; 
    }
    return ans ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t = 1; 
    // cin>>t ; 
    while(t-- > 0 )
    {
        vvi profit = {{1,3},{2,4},{1,15},{1,1},{15,1}} ;
        int k = 3 ;
        cout << solve( profit , k ) << endl ;
    }
    return 0;
}