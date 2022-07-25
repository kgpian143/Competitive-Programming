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
    int n ,  x  ; 
    cin>>n >>  x ; 
    vi v(n , 0 ) ; 
    f( i , 0 , n )cin>>v[i] ; 
    int l = N , r =  0 ;
    int sum = 0 ; 
    for( int i = 0 ; i < n -1 ; i++ )
    {
        sum += abs(v[i] - v[i-1]) ;
    }
    for( int i = 0 ; i < n - 1 ; i++ )
    {
        if( v[i] <=  x ) 
        {
            if( v[i + 1]  <  x )
            {
                int a  = min(v[i] , v[i+1]) ; 
                int b  = max( v[i] , v[i+1]) ; 
                l = min( l ,  a) ;
                r = max( r  , b ) ; 
            }
            else 
            {
                l = min( l ,  v[i] ) ; 
                r = max( r ,  x ) ;
            }
        }
        if( l != 0 ) 
        {
            sum += l - 
            cout<<sum<<endl; 
            return ;
        }
        else  
        {
             
        }
    }
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