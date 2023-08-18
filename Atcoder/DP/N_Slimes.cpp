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
    int n ; 
    cin >> n ;
    vi v( n , 0 ) ;
    for( auto &it : v)cin >> it ;
    vvi dp( n+1 , vi( n+1 , 1e18)) ;

    vi pref( n + 1 , 0 ) ;
    for( int i = 0 ; i < n ; i++ )
    {
        pref[i+1] = pref[i] + v[i] ;
    }

    for( int i = n ; i > 0 ; i--  )
    {
        for( int j = i ; j <= n ; j++ )
        {
            if( i == j )
            {
                dp[i][j] = 0 ;
                continue;
            }
            for( int k = i+1  ; k <= j ; k++)
            {
                dp[i][j] = min( dp[i][j] , dp[i][k-1] + dp[k][j]) ;
            }
            dp[i][j] += pref[j] - pref[i-1] ;
        }
    }
    cout << dp[1][n] << endl ;
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