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
    int n ; 
    cin>>n ;
    vi v ; 
    vi  ans( n , 0 )  ;
    f( i , 0 , n )
    {
        int a  ; 
        cin>>a ; 
        v.push_back(a) ; 
    }
    sort( all(v)) ; 
    if( n & 1 )
    {
         ans[2] = v[0] ; 
         ans[n-1] =v[1] ; 
         int k = 0 ;
         for( int i = 2 ; i < n  ; i++ )
         {
             if( k == n-1 )break ;
             if( k == 2 )k++ ; 
             ans[k++] = v[i] ; 
         }
    }
    else 
    {
         ans[2] = v[0] ; 
         ans[n-2] =v[1] ; 
         int k = 0 ;
         for( int i = 2 ; i < n  ; i++ )
         {
             if( k == n-2 )k++ ;
             if( k == 2.
              )k++ ; 
             ans[k++] = v[i] ; 
         }
    }
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
        solve();
    }
    return 0;
}