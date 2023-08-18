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

void solve()
{
    int n , k , d ;
    cin >> n >> k >> d ; 
    vvi dp( n + 1 , vi(2,0)) ;
    dp[0][0] = 1 ;
    dp[0][0] = 1 ;

    for( int i = 1 ; i <= n ; i++ )
    {
        for( int j = 1 ; j <= k ; j++ )
        {
            if( j > i )continue;
            if( j >= d )
            {
                dp[i][1] =  (dp[i][1] + dp[i-j][1]) % mod ;
                dp[i][1] =  (dp[i][1] + dp[i-j][0]) % mod ;
            }
            else 
            {
                dp[i][0] =  (dp[i][0] + dp[i-j][0]) % mod ;
                dp[i][1] =  (dp[i][1] + dp[i-j][1]) % mod ;
            }
        }
    }
    cout << dp[n][1] << endl ;
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