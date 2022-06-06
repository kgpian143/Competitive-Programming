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
    string s1 , s2 ;
    cin>>s1>>s2 ;
    vector<vi> dp( s1.size() + 1 , vi(s2.size() + 1));
    for( int i = 0 ; i  < s1.size() ; i++ )
    {
        for( int j = 0 ; j < s2.size() ; j++ )
        {
            if( i == 0 )
            {
                if( s1[i] == s2[j] )dp[i][j] = j ;
                else 
                dp[i][j] = min( j+1 , 1+dp[i][j-1] );
            }
            else if( j == 0 )
            {
                if( s1[i] == s2[j] )dp[i][j] = i ;
                else 
                dp[i][j] = min( i+1 , 1+dp[i-1][j] );
            }
            else if( s1[i] == s2[j] )dp[i][j] = dp[i-1][j-1] ;
            else 
            {
                int op1 = min( dp[i-1][j] , dp[i-1][j-1]);
                int op2 = min( dp[i][j-1] , op1);
                dp[i][j] = 1 + op2 ;
            }
        }
    }
    cout<<dp[s1.size() - 1][s2.size() -1];
    return 0;
}