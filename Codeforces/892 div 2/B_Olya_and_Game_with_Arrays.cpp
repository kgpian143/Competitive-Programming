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
    vi arr[n] ;
    int mn = 1e9 + 1 , sum2 = 0 ;
    for( int i = 0 ; i < n ; i++ )
    {
        int a ;
        cin >> a ;
        for( int j = 0 ; j < a ; j++ )
        {
            int u ; 
            cin >> u ;
            arr[i].push_back(u) ;
        }
        sort( all(arr[i])) ;
        sum2 += arr[i][1] ;
        mn = min( mn , arr[i][0]) ;
    }
    int ans = -1 ;
    for( int i = 0 ; i < n ; i++ )
    {
        ans = max( ans , sum2 - arr[i][1] + mn ) ;
    }
    cout << ans << "\n" ;
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