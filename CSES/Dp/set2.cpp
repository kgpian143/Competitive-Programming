#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
typedef vector<int> vi; 
typedef vector<string> vs; 
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef map<long long, long long> mll;
typedef pair<int, int> pii;  
typedef pair<long long, long long> pll; 
typedef unsigned long long ull; 
typedef long double ld; 
typedef long long ll; 
typedef vector<vector<int>> vvi; 
typedef vector<pii> vpii; 

int main()
{
    // int t ;
    // cin>>t ;
    int n ;
    cin>>n ;
    if( (n*(n+1)/2) % 2 == 1)
    {
         cout<<0<<endl;
    }
    else 
    {
        int k = n*(n+1)/4  ;
        vector<vi> dp(n+1,vi(k+1 , 0 )) ;
        // memset( dp , 0  ,  sizeof dp) ;
        dp[0][0] = 1 ;
        for( int i =  1 ; i <= n ; i++ )
        {
            for( int j = 1 ; j <= k ; j++ )
            {
                 dp[i][j] = dp[i-1][j] ;
                 if( j - i >= 0 )dp[i][j] = (dp[i][j]+dp[i-1][j-i])%mod ;
            }
        }
        cout<<dp[n][k]%mod;
    }
    return 0;
}