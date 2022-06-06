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
    int n ;
    cin>>n ;
    vi dp(100000+1,0);
    vi val(n+1,0);
    f(i,1,n+1)cin>>val[i] ;
    int cnt = 0 ;
    dp[0] = 1 ;
    for( int i = 1 ; i <= n ; i++)
    {
         for( int j = 100000 ; j >= val[i] ; j-- )
         {
             if( dp[j] == 1 )continue;
             dp[j] = dp[j-val[i]];
             if( dp[j - val[i]] == 1 )cnt++ ;
         }
    }
    cout<<cnt<<endl;
    for( int i = 1 ; i <= 100000 ; i++)
    {
        if(dp[i] == 1)cout<<i<<" ";
    }
    return 0;
}