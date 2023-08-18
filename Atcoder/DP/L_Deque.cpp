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
const int N = 1e5 + 5 ;

void solve()
{
    int n ; 
    cin >> n ; 
    vi v( n , 0 ) ; 
    for( auto &it : v )cin >> it ;
    vvi dp( n + 1 , vi ( n + 1 , 0  )) ;
    for( int l = n ; l > 0 ; l-- )
    {
        for( int k = l ; k <= n ; k++ )
        {
            if( l == k )
            {
                dp[l][k] = v[l-1] ;
            }
            else if( ( k - l )  == 1 )dp[l][k] = abs( v[k-1] - v[l-1]) ;
            else 
            {
                int ans = max( v[l-1] - dp[l+1][k] , v[k-1] - dp[l][k-1]  ) ;
                dp[l][k] = ans ;
            }
        }
    }
    cout << dp[1][n] << endl ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t = 1; 
    // cin>>t ; 
    while(t-- > 0 )
    {
        solve() ;
    }
    return 0;
}