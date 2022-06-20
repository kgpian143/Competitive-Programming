#include<bits/stdc++.h>
using namespace std ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long 
typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef pair<int, int> pii;  
typedef pair<int, bool> pib;  
typedef unsigned long long ull; 
typedef long double ld; 
typedef vector<pii> vpii; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
const int N = 2e5 + 5; 

void solve() 
{
    int n , m ;
    cin>>n >> m ;
    int g[41][41] ;
    int a , b  , max_num = INT_MIN ;
    f( i , 0 , n )
    {
        f( j ,0 , m )
        {
            cin>>g[i][j] ;
            if( g[i][j] > max_num )
            {
                a = i ;
                b = j ;
                max_num = g[i][j] ;
            }
        }
    }
    // cout<<a<<" "<<b<<endl;
    int h = max( n - a , a + 1) ;
    int w = max( m - b , b + 1 ) ;
    cout<<h*w<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        solve();
    }
    return 0;
}