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
    cin>> n ; 
    int child[n+1] ;
    vi a(n + 1 , 0) , b(n + 1 , 0 ) , d( n + 1 , 0 ); 
    f( i , 0 , n )cin>>a[i] ;  
    f( i , 0 , n )cin>>b[i] , child[a[i]] = b[i] ; 
    f( i , 0 , n )cin>>d[i] ; 
    vi hsh( n + 1 , 0 ) ;
    int ans = 1 ; 
    for( int i = 0 ; i < n ; i++ )
    {
        if( hsh[a[i]] )continue;
        if( d[i] != 0 || a[i] == b[i])
        {
            hsh[a[i]] = 1 ;
            int p = child[a[i]] ;
            while( p != a[i])
            {
                hsh[p] = 1 ;
                p = child[p] ;
            }
        }
    }
    for( int i = 0 ; i < n ; i++ )
    {
        if( hsh[a[i]] )continue;
        // cout<<"okk\n" ;
        if( d[i] == 0 )
        {
            hsh[a[i]] = 1 ;
            int p = child[a[i]] ;
            while( p != a[i])
            {
                hsh[p] = 1 ;
                p = child[p] ;
            }
        }
        ans = (ans*2) % mod  ;
    }
    cout<<ans<<endl;
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