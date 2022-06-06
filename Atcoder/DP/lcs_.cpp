#include<bits/stdc++.h>
using namespace std ;
int main()
{
    string s , t ;
    cin>>s>>t ;
    int dp[s.length()+1][t.length()+1];
    memset(dp,0,sizeof(dp));
    // vector<vector<pair<int,pair<int,int>>>> dp( s.length()+ 1 , vector<pair<int,pair<int,int>>>(t.length()+1,{0,{0,0}}));
    for( int i = 0 ; i < s.length() ; i++ )
    {
        for( int j = 0 ; j < t.length() ;j++ )
        {
            if(s[i] == t[j])
            {
                dp[i+1][j+1] = max( dp[i+1][j+1] , 1+dp[i][j]);
            }
            else dp[i+1][j+1] = max( dp[i][j+1] , dp[i+1][j]) ;
        }
    }
    // for( int i = 0 ; i < s.length() ; i++ )
    // {
    //      for( int j = 0 ;  j < t.length() ; j++)
    //      {
    //          cout<<dp[i+1][j+1]<<" ";
    //      }
    //      cout<<endl ;
    // }
    cout<<dp[s.length()][t.length()];
    return 0;
}