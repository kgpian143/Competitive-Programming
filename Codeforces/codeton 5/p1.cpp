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
const int N = 1e5 ;


void solve()
{
   int n ;
   cin >> n ;
   vi v(n) ;
   vi dp( N , -1e9) , maxx( N , -1e9) ;

   dp[0] = 0 ;
   for( auto &i : v )cin >> v[i] ;
   for( int i = 1 ; i <= n ; i++ )
   {
       dp[i] = max( dp[i-1] , i + maxx[v[i-1]]) ;
       maxx[v[i]] = max( maxx[v[i-1]] , dp[i-1] - ( i - 1) ) ;
   }
   cout << dp[n] << endl;

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