#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5 + 10 ;
int dp[N] , h[N] ;
int k ;
int mincost( int n  )
{
    if(dp[n] != -1)return dp[n] ;
    else if( n == 1 )return dp[1] = 0 ;
    // else if( n == 2)return dp[2] = abs(h[2] - h[1]);
    // else return dp[n] = min( (mincost(n-2) + abs( h[n] - h[n-2])) , (abs( h[n] - h[n-1]) + mincost(n-1)) );
    int cost = INT_MAX ;
    cost = min( cost ,  mincost(n-1) + abs(h[n] - h[n-1]));
    {
        for( int i = 2 ; i <= k ; i++)
        {
            if( i >= n)break;
            cost = min( cost ,  mincost(n-i) + abs(h[n] - h[n-i]));
        }
    }  
    return dp[n] = cost ;

}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n ;
    cin>>n>>k ;
    for( int i = 1 ; i <= n ; i++)cin>>h[i] ;
    cout<<mincost(n);
    return 0;
}