#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define int  long long  
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<int> vl;
typedef vector<vector<int>> vvl; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii;
typedef map<int, int> mll;
typedef pair<int, int> pii;  
typedef pair<int, bool> pib; 
typedef pair<int, int> pll; 
typedef unsigned int ull; 
typedef long double ld; 
typedef int ll; 
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;
const int N = 2e5 + 5 ;


void solve()
{
   int n ;
   cin >> n ;
   vi v(n+1) ;
   vi dp( n+1 , -1e9) , maxx( n+1 , -1e9) ;

   dp[0] = 0 ;
   for( int i = 0 ; i < n ; i++ )cin >> v[i+1] ;
   for( int i = 1 ; i <= n ; i++ )
   {
       dp[i] = max( dp[i-1] , i + maxx[v[i]]) ;
       maxx[v[i]] = max( maxx[v[i]] , dp[i-1] - ( i - 1) ) ;
   }
   cout << dp[n] << "\n";

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ; 
    cin>>t ; 
    while(t-- > 0 )
    {
       solve() ;
    }
    return 0;
}