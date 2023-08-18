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

void solve()
{
    int n , k ;
    cin >> n >> k ;
    vi v( n , 0 ) ;
    for( int i = 0 ; i < n ; i++)
    {
        cin >> v[i] ;
    }
    vvi dp( n + 1 , vi( k+1 , 0 )) ;
    dp[0][0] = 1 ; 
    for( int i = 1 ; i <= n ; i++ )
    {
        dp[i][0] = 1 ;
        for( int j = 1 ; j <= k  ; j++ )
        {
            if( v[i-1] >= j )dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod ;
            else 
            {
                dp[i][j] = (dp[i][j-1] + dp[i-1][j] - dp[i-1][j-v[i-1]-1] + mod ) % mod  ;
            } 
        }
    }
    cout << dp[n][k] << endl ;
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