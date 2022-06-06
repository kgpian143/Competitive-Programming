#include<bits/stdc++.h>
using namespace std ;
const int N = 100000;
// int dp[N] ;
// int a[N], b[N] , c[N] , index[N] ;

int main()
{
    // memset( dp , -1 , sizeof(dp));
    int n ;
    cin>>n ;
    vector<int> dp(3) ;
    for( int i = 1 ; i <= n ; i++ )
    {
        // int a , b , c ;
        vector<int> new_dp(3,0) ;
        vector<int> a(3) ;
        for( int i = 0 ; i < 3 ; i++)cin>>a[i] ;
        for( int i = 0 ; i < 3 ; i++)
        {
            for( int j = 0 ; j < 3 ; j++)
            {
                if( i != j)
                {
                    new_dp[i] 
                }
            }
        }
    }
    // cout<<solve(n) ;
    return 0;
}