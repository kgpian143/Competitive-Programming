#include<bits/stdc++.h>
using namespace std ;
string dp[3005][3005];
string solve(string s, string t , int s_size , int t_size)
{
    if( dp[s_size][t_size] != "\n")return dp[s_size][t_size] ;
    if( s_size == 0 || t_size == 0 )
    {
        return dp[0][0] = "";
    }
    if( s[s_size-1] == t[t_size-1])
    {
        string str = solve(s,t,s_size-1,t_size-1) ;
        str.push_back(s[s_size-1]);
        return dp[s_size][t_size] = str; 
    }
    else 
    {
       vector<string> str(3) ;
       str[1] = solve(s,t,s_size,t_size-1) ; 
       str[2] = solve(s,t,s_size-1,t_size) ; 
    //    str[0] = solve(s,t,s_size-1,t_size-1) ; 
       int i = 1 ;
       if( str[1].size() < str[2].size() )i = 2 ;
    //    if( str[0].size() > str[2].size() && i == 2)i = 0 ;
       return dp[s_size][t_size] = str[i];
    }
}
int main()
{
    for( int i = 0 ; i < 3005 ; i++)
    {
        for( int j = 0 ;  j < 3005 ; j++)dp[i][j] = "\n" ;
    }
    string s ,  t ;
    cin>>s>>t ;
    cout<<solve(s,t,s.size(),t.size()) ;
    return 0;
}