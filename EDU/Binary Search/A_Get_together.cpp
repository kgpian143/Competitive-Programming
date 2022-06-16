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
int n ;
vpii dist ;
bool good( double t )
{
    double leftx = -(1e9 + 10 );
    double rightx = 1e9 + 10 ;
    for( int i = 0 ; i < n ; i++ )
    {
        leftx = max( leftx , dist[i].first - dist[i].second * t ) ;
        rightx = min( rightx , dist[i].first + dist[i].second * t ) ;
    }
    // cout<<leftx<<" "<<rightx << endl;
    if( rightx - leftx >= 0 )return true ;
    else return false ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    cin>>n ;
    for( int i = 0 ; i < n ; i++ )
    {
        int st , end ;
        cin>>st>>end;
        dist.push_back({st, end}) ;
    }
    cout<<setprecision(20);
    double l = 0 ,  h = 2e9 + 10  ;
    for( int i = 0 ; i < 100 ; i++ )
    {
        double m = ( l + h )/2 ;
        if( good(m) )h = m ;
        else l = m ;
        // cout<<l << " "<< h << endl;
    }
    
    cout<<h ;
    return 0;
}