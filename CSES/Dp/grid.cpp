#include<bits/stdc++.h>
using namespace std ;
char grid[1005][1005] ;
int  dp[1005][1005] ;
long long int solve( int h , int w)
{
    if( dp[h][w] != -1)return dp[h][w] ;
    if( grid[h][w] == '*')return 0 ;
    if( h == 1 )
    {
        for( int i = 1 ; i <= w ; i++ )
        {
            if(grid[h][i] == '*')return dp[h][w] = 0 ;
        }
        return dp[h][w] = 1 ;
    }
    else if( w == 1 )
    {
        for( int i = 1 ; i <= h ; i++ )
        {
            if(grid[i][w] == '*')return dp[h][w]  =  0 ;
        }
        return dp[h][w] = 1 ;
    }
    long long int p = 0 ;
    if( grid[h-1][w] != '*')p += solve(h-1,w) ;
    if( grid[h][w-1] != '*')p += solve(h,w-1) ;
    return dp[h][w] = p%1000000007 ;
}
int main()
{
    memset(dp,-1 , sizeof(dp));
    int n ;
    cin>>n ;
    for( int i = 1 ; i <= n ; i++)
    {
        for( int j = 1 ; j <= n ; j++)cin>>grid[i][j] ;
    }
    cout<<solve(n,n) ;
    return 0;
}