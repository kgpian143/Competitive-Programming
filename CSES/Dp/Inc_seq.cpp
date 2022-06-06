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
// #define max_  (1e9 + 1);
int main()
{
    // int t ;
    // cin>>t ;
    int n ;
    cin>>n ;
    vi A(n+1 , 0 ) ;
    f(i,0,n)cin>>A[i+1] ;
    vi dp(n+1, 1e9 + 1 );
    for( int i = 1 ; i <= n ; i++)
    {
         vi::iterator it  =  lower_bound( dp.begin() + 1, dp.end() , A[i]) ;
         int index = it - dp.begin() ;
         dp[index] = A[i] ;
    }
    int max1 = 0 ;
    for( int i = 1 ; i <= n ; i++ )
    {
        if( dp[i] == 1e9 + 1 )
        {
            max1 = i - 1 ;
            break; 
        }
    }
    if( max1 == 0 )cout<<n ;
    else cout<<max1;
    return 0;
}
//10
//3 8 3 8 1 5 10 5 8 10