#include<bits/stdc++.h>
using namespace std ;
# define mod 1000000007 
int dice[7]  ;
int main()
{
    for( int i = 1 ; i <= 6 ; i++ )
    {
         dice[i] = i ;
    }
    int n ;
    cin>>n ;
    int dp[n+1] ;
    memset(dp,0,sizeof(dp));
    dp[0] = 1 ;
    for( int i = 1 ; i <= n ; i++ )
    {
        for( int j = 1 ; j <= 6 ; j++ )
        {
            if( dice[j] > i )break ;
            dp[i] = (dp[i]+ dp[i-j])%mod ;
        }
    }
    cout<<dp[n] ;
    return 0;
}