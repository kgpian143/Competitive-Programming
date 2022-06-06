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
    int n , m ;
    cin>>n>>m ;
    vi v(n+1 ,0 );
    // int cnt = 0 ;
    f(i,1,n+1)
    {
        cin>>v[i] ;
    }
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for( int i = 1 ; i  <= n ; i++  )
    {
        for( int j = 1 ; j <= m ; j++)
        {
            if( i == 1 )
            {
                if( v[i] == j || v[i] == 0 )dp[i][j] = 1 ;
                else dp[i][j] = 0 ;
            }
            else 
            {
                if( v[i] == 0 || v[i] == j )
                {
                    dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j])%mod + dp[i-1][j+1])%mod ;
                }
                else dp[i][j] = 0 ;
            }
        }
    }
    int ans = 0  ; 
    for( int i = 1 ; i <= m ; i++ )ans = (ans + dp[n][i])%mod ;
    cout<<ans;
    return 0;
}