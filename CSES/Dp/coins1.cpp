#include<bits/stdc++.h>
using namespace std ;
# define mod 1000000007 
int main()
{
    
    int n , x ;
    cin>>n>>x ;
    int dp[x+1] , val[n+1] ;
    for( int i = 1 ; i <= n ; i++ )
    {
         cin>>val[i] ;
    }
    memset(dp,0,sizeof(dp));
    dp[0] = 1 ;
    for( int i = 1 ; i <= x ; i++ )
    {
        for( int j = 1 ; j <= n ; j++ )
        {
            if( val[j] > i )continue ;
            dp[i] = (dp[i]+ dp[i-val[j]])%mod ;
        }
    }
    cout<<dp[x] ;
    return 0;
}