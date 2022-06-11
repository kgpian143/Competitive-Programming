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
int n ,  d  , l , r ;
vi v ;
bool good( int x )
{
    double pref[n+1] ;
    pref[0] = 0 ;
    
    for( int i = 0 ; i < n ; i++ )
    {
        pref[i+1] = pref[i] + v[i] - x ;
    }
    int minPref[n+1] ;
    minPref[0] = 0 ;
    minPref[1] = 1 ;
    for( int i = 2 ; i <= n ; i++ )
    {
        if( pref[i] < pref[minPref[i-1]]) minPref[i] = i ;
        else minPref[i] = minPref[i-1] ;
    }
    for( int i = d ; i <= n ; i++ )
    {
        if( pref[minPref[i-d]] <= pref[i] )
        {
           l = minPref[i-d] + 1 ;
           r = i ;
           return true ;
        } 
    }
    return false ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t = 1;
    // cin>>t ;
    while(t-- > 0 )
    {
        cin>>n>>d ;
        v.resize(n) ;
        f(i,0,n)cin>>v[i] ;
        // if( n == 2 )cout<<1<<" "<<2;
        // else 
        // {
        double i = -1 ;
        double j = 1e9 + 1 ;
        int k = 0 ;
        while( k < 50 )
        {
            double m = ( i + j )/2 ;
            if( good(m) )i = m ;
            else j = m ;
            k++ ;
            cout<<i<<" "<<j<<" "<<l<<" "<<r<<endl;
        }
        cout<<i<<" "<<l<<" "<<r;
        // }
    }
    return 0;
}