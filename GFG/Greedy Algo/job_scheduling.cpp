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

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
bool comp( Job j1 , Job j2 ) 
{
    // if( j1.dead != j2.dead )return j1.dead < j2.dead ;
    return j1.profit > j2.profit ;
}
//  int bsearch( Job arr[] , int k ) 
//  {
//     int l = -1 ; 
//     int h = k+1 ;
//     while( h - l > 1 )
//     {
//         int m = ( h + l )/2  ;
//         if( arr[m].dead  )
//     }
//  }
 vector<int> JobScheduling(Job arr[], int n) 
{ 
    int time = 0 , max_profit  = 0 , cnt = 0 ;
    sort( arr , arr+ n , comp ) ;
    // dp[1] = arr[0].profit ;
    vector<bool> vis ( 101 , false ) ;
    vector<int> ans ;
    for( int i = 0 ; i < n ; i++ )
    {
        
    }
    ans.push_back( cnt ) ;
    ans.push_back( max_profit ) ;
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
        // solve();
        int n ;
        cin>>n ;
        Job J[n] ;
        f( i , 0 , n )
        {
            int a , b  ,  c ;
            cin>>a>>b>>c ;
        }
        vi  ans   = JobScheduling ( J , n) ;
        cout<<ans[0] << " " << ans[1] ;
    }
    return 0;
}