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
    cin>>n>> m ; 
    vi v( n , 0 ) ; 
    f( i , 0 , n )cin>>v[i] ; 
    vi pref( n + 1 , 0 ) ; 
    vi suff( n + 1 , 0 ) ; 
    for( int  i = 0 ; i < n-1 ; i++ )
    {
        if( v[i+1] < v[i])pref[i+1] = pref[i] + v[i] - v[i+1] ; 
        else pref[i+1] = pref[i] ;
        if( v[i+1] > v[i] )suff[i+1] = suff[i] + v[i+1] - v[i] ; 
        else suff[i+1] = suff[i] ;
    }
    while( m-- > 0 )
    {
        int s  , t ; 
        cin>>s>>t ;
        if( s < t )
        {
            cout<<pref[t-1] - pref[s-1]<<endl  ; 
        }
        else cout<< suff[s-1] - suff[t-1]<<endl ;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t = 1;
    // cin>>t ;
    while(t-- > 0 )
    {
        solve();
    }
    return 0;
}