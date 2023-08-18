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
    mii m ;
    for( auto &it : v )cin >> it , m[it]++  ;
    int q ;
    cin >> q ;
    vi ans ;
    while( q-- > 0 )
    {
        int x , y ; 
        cin >> x >> y ;

        int l = x/2 - 1 ;
        int h = 1e9 + 1 ;
        while( h - l > 1 )
        {
            int mid = ( h + l ) >> 1 ;
            if( mid * ( x - mid ) >= y ) l = mid ;
            else h = mid ;
        }

        if( l * ( x - l ) == y )
        {
            if( l == ( x - l ))
            {
                ans.push_back( m[l] * ( m[l] - 1 ) / 2 ) ;
            }
            else 
            {
                ans.push_back( m[l] * m[x-l] ) ; 
            }
        }
        else ans.push_back(0) ;
    }
    for( auto it : ans)cout << it << " ";
    cout << "\n" ;
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