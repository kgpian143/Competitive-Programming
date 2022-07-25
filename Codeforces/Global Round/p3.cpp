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
    cin>>n>>m ;
    vi v1( n , 0 ) ;
    f( i , 0 , n )cin>>v1[i] ;
    int k ;
    cin>>k ;
    vi v2( k , 0 ) ;
    f( i , 0 , k )cin>>v2[i] ;
    if( n >= k )
    {
        int sum = 0 , i = 0 , j = 0 ;
        while( i < n && j < k )
        {
            sum += v1[i] ;
            if( sum == v2[j] )
            {
                sum = 0 ;
                i++ ;
                j++ ;
            }
            else if( sum < v2[j] )
            {
                if( v1[i] % m != 0 )
                {
                    cout<<"NO" << endl ;
                    return  ;
                }
                sum += v1[i] ;
                i++ ;
            }
            else 
            {
                if( v1[i] % m != 0 )
                {
                    cout<<"NO"<< endl ;
                    return  ;
                }
                else 
                {
                     sum = sum - v2[j] ;
                     i++ ;
                     j++ ;
                }
            }
        }
         if( sum == 0 )cout<<"YES"<<endl; 
        else cout<<"NO"<<endl;
    }
    else 
    {
        int sum = 0 , i = 0 , j = 0 ;
        while( i < k && j < n )
        {
            sum += v2[i] ;
            if( sum == v1[j] )
            {
                sum = 0 ;
                i++ ;
                j++ ;
            }
            else if( sum < v1[j] )
            {
                if( v2[i] % m != 0 )
                {
                    cout<<"NO" << endl ;
                    return  ;
                }
                sum += v2[i] ;
                i++ ;
            }
            else 
            {
                if( v2[i] % m != 0 )
                {
                    cout<<"NO"<< endl ;
                    return  ;
                }
                else 
                {
                     sum = sum - v1[j] ;
                     i++ ;
                     j++ ;
                }
            }
        }
        if( sum == 0 )cout<<"YES"<<endl; 
        else cout<<"NO"<<endl;
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