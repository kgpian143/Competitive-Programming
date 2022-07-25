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
    int n , a , b  ; 
    cin>>n>>a>>b ; 
    vi v( n , 0 ) ;
    f( i , 0 , n )cin>>v[i] ; 
    int cp = 0 ; 
    int cost = 0 ; 
    for( int i = 1 ; i < n ; i++ )
    {
        if( a * ( v[i-1] - cp ) + b*( v[i] - v[i-1]) <= b * ( v[i] - cp ) )
        {
            // cost += a * abs( v[i-1] - cp ) + b*( v[i] - v[i-1]) ; 
             cp = v[i-1] ; 
        }
        // else cost += b * ( v[i] - cp ) ; 
    }
    // cost = b*(v[0]) ;
    cout<<cp<<endl;
    int cp1 = 0 ; 
    for( int i = 0 ; i < n ; i++ )
    {
        cost += b * ( v[i] - cp1) ; 
        if( cp1 < cp ) 
        {
           cost += a*( v[i] - cp1 ) ; 
           cp1 = v[i] ;
        }
    }
    cout<<cost<<endl ;
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