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
    int sm = 0 , mx = -1 ;
    vi pref( n + 1 , 0 ) ;
    for( int i = 1 ;  i <= n  ; i++ )
    {
        sm += i * i ;
        pref[i] = sm ; 
    }
    int ans = -1 ;
    for( int i = 1 ; i < n ; i++ )
    {
        sm = pref[n-i-1] ;
        mx = -1 ;
        for( int j = n - i , k = 0 ; j <= n ; j++ )
        {
            sm += j * ( n - k ) ; 
            mx = max( mx , j * ( n - k)) ;
            k++ ;
        }
        ans = max( ans , sm - mx ) ;
    }
    cout << ans << endl ;
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