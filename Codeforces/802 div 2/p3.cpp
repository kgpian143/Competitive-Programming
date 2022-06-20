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
#define getv(v,n) for( int i = 0 ; i < n ; i++)cin>>v[i];
#define putv(v) for(auto it : v )cout<<it<<' ';
const int N = 2e5 + 5; 

void solve() 
{
    int n ;
    cin>>n ;
    vi v( n , 0 ) ;
    getv( v , n) ;
    int suff = 0 ;
    int ans = 0  ;
    int minm = v[0] ;
    f( i , 0 , n - 1)
    {
        if( v[i] >  v[i+1] )
        {
            ans += ( v[i] - v[i+1]) ;
            minm = v[i+1] + suff;
        }
        else if( v[i] < v[i+1] )
        {
            suff -= v[i+1] - v[i] ;
            ans += v[i+1] - v[i] ;
        }
    }
    ans += abs(minm) ;
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