#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
typedef vector<int> vi; 
typedef vector<vector<int>> vvi; 
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
int dp[1001][1001] ;
int main()
{
    int n ,  q  ;
    cin>>n>>q ;
    char v[n+1][n+1] ;
    for( int i = 1 ; i <= n ;  i++)
    {
        for( int j = 1 ; j <= n ; j++ )
        {
            cin>>v[i][j] ;
        }
    }

    for( int i = 1 ; i <= n ; i++ )
    {
        for( int j = 1 ; j <= n ; j++ )
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + ( (v[i][j] == '*') ? 1 : 0) ;
        }
    }
    // for( int i = 1 ; i <= n ;  i++)
    // {
    //     for( int j = 1 ; j <= n ; j++ )
    //     {
    //         cout<<dp[i][j];
    //     }
    //     cout<<endl;
    // }
    while(q-- > 0 )
    {
         int x1 , y1 , x2 , y2 ;
         cin>>y1>>x1>>y2>>x2 ;
         cout<<( dp[y2][x2] - dp[y2][x1-1] - dp[y1-1][x2] + dp[y1-1][x1-1])<<endl ;
    }
    return 0;
}
/*
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2
*/