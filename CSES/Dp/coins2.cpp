#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
// int price[7]  ;
int main()
{
    
    int n , x ;
    cin>>n>>x ;
    int dp[n+1][x+1] , price[n+1] ;
    for( int i = 1 ; i <= n ; i++ )
    {
        cin>>price[i]  ;
    }
    for( int i = 1 ; i <= n ; i++ )
    {
        for( int j = 0 ; j <= x ; j++)
        {
            if( j == 0 )dp[i][j] = 1 ;
            else 
            {
                int op1 = ( price[i] > j ) ? 0 : dp[i][j - price[i]] ;
                int op2 = ( i == 1 ) ? 0 : dp[i-1][j] ;
                dp[i][j] = (op1 + op2)%mod ;
            }
        }
    }
    cout<<dp[n][x] ;
    return 0;
}