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

void solve( ) 
{
    int n ,  m , k ;
    vi v1( n , 0 ) , v2( m , 0 ) , v3( k , 0 ) ;
    for( int i = 0 ; i < n ; i++ )cin>>v1[i] ;
    for( int i = 0 ; i < m ; i++ )cin>>v2[i] ;
    for( int i = 0 ; i < k ; i++ )cin>>v3[i] ;
    vi  ans  ;
    int i = 0  , j = 0 ; 
    while( i < n && j < m )
    {
        if( v1[i] == v2[j])
        {
            ans.push_back(v1[i]) ;
            i++ ;
            j++ ;
        }
        else if( v1[i] > v2[j] )j++ ;
        else i++ ;
    }
    vi ans1 ;
    i = 0 , j = 0 ;
    while( i < ans.size() && j < k  )
    {
        if( ans[i] == v3[j])
        {
            ans1.push_back(v3[j]) ;
            i++ ;
            j++ ;
        }
        else if( ans[i] > v3[j]) j++ ;
        else i++ ;
    }
    for( auto it : ans1 )cout<<it<<" ";
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