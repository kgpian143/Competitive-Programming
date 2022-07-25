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
    vi  v( m , 0 ) ; 
    mii mp ; 
    f( i ,0 , m )cin>>v[i] , mp[v[i]]++;  
    if( m <= n )
    {
         if( mp.size() < m )cout<<2<<endl ;
         else cout<<1<<endl ;
    }
    else 
    {
        int l = 0 , h = N ; 
        while( h - l > 1 )
        {
            int mid = ( l + h )/2  ; 
            int cnt = 0 ; 
            for( int i = 1 ; i <= n ; i++ )
            {
                if( mp[i] >= mid ) cnt += mid ; 
                else 
                {
                    cnt += mp[i] + ( mid - mp[i]) / 2  ;
                }
            }
            if( cnt >= m ) h = mid  ; 
            else l = mid  ;
        }
        cout<<h<<endl ;
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