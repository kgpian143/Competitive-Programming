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

int getsmallestarea( vector<vector<int>> grid , int m , int n )
{
    int min_left = n+1 , min_top = m+1 , max_right = -1 , max_bottom = -1 ;
    for( int i = 0 ; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                if( grid[i][j] == 1 )
                {
                    min_left = min( min_left , j ) ;
                    min_top = min( min_top , i ) ;
                    max_right = max( max_right , j ) ; 
                    max_bottom = max( max_bottom , i ) ; 
                }
            }
        }
    int ans = ( max_right - min_left + 1 ) * ( max_bottom - min_top + 1 ) ;
    return ans ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ; 
    cin>>t ; 
    while(t-- > 0 )
    {
        int m , n ; 
        cin >> m >> n ; 
        vector<vector<int>> grid( m , vector<int> (n , 0)) ; 
        for( int i = 0 ; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                cin >> grid[i][j] ;
            }
        }
        int area = getsmallestarea( grid , m , n );
        cout << area << endl ;
    }
    return 0;
}