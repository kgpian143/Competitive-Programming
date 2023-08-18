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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t = 1 ; 
    // cin>>t ; 
    while(t-- > 0 )
    {
        int n , k  ;

        cin >> n >> k ;
        int dp[n] ; 
        memset( dp ,  -1 , sizeof(dp));

        vi h( n , 0 ); 
        f( i ,0 , n ) cin >> h[i] ; 
        dp[1] = 0 ; 
        for( int i = 2 ; i <= n ; i++){
            dp[i] = dp[i-1] + abs(h[i-1] - h[i-2]) ;
            for( int j = 2 ; j <= k ; j++ )
            {
                if( i - j < 1)break ;
                dp[i] = min( dp[i] , dp[i-j] + abs(h[i-1] - h[i-j-1]) ) ;
            }
        }
        cout << dp[n] << endl ;
    }
    return 0;
}