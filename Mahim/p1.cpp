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
const int N = 1e5 + 5 ;

void solve()
{
    int dp[N] , n , k  ;
    string s ;
    cin>> n >> k ; 
    cin >> s ; 
    dp[0] = 1;
    for( int i = 1 ; i <= n ; i++ )
    {
        int sm = 0 , dec = 1 ;
        for( int j = i-1 ; j >= 0 ; j-- ){
            sm = sm + dec * ( s[j] - '0') ;
            if( sm > k )break; 
            dp[i] = ( dp[j] + dp[i]) % mod ; 
            dec *= 10 ; 
        }
    }
    cout << dp[n] << "\n"; 
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