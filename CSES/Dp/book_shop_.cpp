#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
// int price[7]  ;
int main()
{
    
    int n , x ;
    cin>>n>>x ;
    int dp[n+1][x+1] , price[n+1] , pages[n+1] ;
    for( int i = 1 ; i <= n ; i++ )
    {
        cin>>price[i]  ;
    }
    for( int i = 1 ; i <= n ; i++ )
    {
        cin>>pages[i]  ;
    }
    dp[0][0] = 0 ;
    for( int i = 0 ; i <= x ; i++ )dp[0][i] = 0 ;
    for( int i = 1 ; i <= n ; i++ )
    {
        for( int j = 0 ; j <= x ; j++)
        {
            if( j == 0 )dp[i][j] = 0 ;
            else 
            {
                // int op1 = ( price[i] > j ) ? 0 : dp[i][j - price[i]] ;
                // int op2 = ( i == 1 ) ? 0 : dp[i-1][j] ;
                // dp[i][j] = (op1 + op2)%mod ;
                if( price[i] > j )
                {
                    dp[i][j] = dp[i-1][j] ;
                }
                else 
                {
                    int op2 =  dp[i-1][j] ;
                    int op1 = dp[i-1][j-price[i]] + pages[i] ;
                    dp[i][j] = max( op2 , op1 );
                }
            }
        }
    }
    cout<<dp[n][x] ;
    return 0;
}