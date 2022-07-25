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
int findMaxProduct(vector<int> &a, int n){
        //Write your code here
        // int ans = 1  ;  
        sort( a.begin() , a.end() ) ;
        int ind = -1 ;
        int ans = 0 ;
        for( int i = 0 ; i < n ; i++ )
        {
            if( a[i] >= 0 )break ;
            ind = i ;
        }
        cout<<ind<<endl;
        if( (ind + 1) % 2 == 0 ) 
        {
             for( int i = 0 ; i < n ; i++ )
             {
                 if( a[i] == 0  )continue ;
                 if( ans == 0 )ans = abs(a[i]) ;
                 else 
                 {
                    ans = ( ans * abs(a[i]))%mod ;
                 }
             }
        }
        else 
        {
            for( int i = 0 ; i < n ; i++ )
             {
                 if( a[i] == 0  || i == ind  )continue ;
                 if( ans == 0 )ans = abs(a[i]) ;
                 else 
                 {
                    ans = ( ans * abs(a[i]))%mod ;
                 }
             }
        }
        return ans  ;
    }
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n ; 
        cin>> n ;
        vi  v( n , 0 ) ;
        f( i , 0 , n )cin>> v[i] ; 
        cout<<findMaxProduct( v , n ) << endl;
    }
    return 0;
}