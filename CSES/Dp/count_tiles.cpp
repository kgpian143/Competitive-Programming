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
    int a  , b ;
    cin>>a>>b ;
    vector<vi> dp( a+1 ,  vi(b+1 ,  0) );
    dp[2][2] = 2 ;
    for( int i = 1 ; i <= a ; i++)
    {
        for( int j = 1 ; j <= b ; j++)
        {
            if( i*j % 2 == 1 )dp[i][j] = 0 ;
            else if( i == 1 )
            {
                dp[i][j] = j/2 ;
            }
            else if( j == 1 )
            {
                dp[i][j] = i/2 ;
            }
            else 
            {
                dp[i][j] = dp[i-2][j-2] + dp[2][j-2] + dp[i-2][2] + dp[2][2] ;
            }
        }
    }
    cout<<dp[a][b] ;
    return 0;
}