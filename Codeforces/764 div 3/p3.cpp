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
    vi v( n , 0 ) ;
    mii m ; 
    f( i , 0 , n ) 
    {
        int a  ; 
        cin>>a  ; 
        while( a > n || m[a] != 0 && a > 0  ) a = a >> 1 ;
        v[i] = a  ;
        m[a]++ ;
    }
    sort(all(v)) ; 
    for( int i = 1 ; i <= n ; i++ )
    {
        int a = i ;
        while( m[a] == 0 )
        {
            a = a << 1 ;
            if( a > n )
            {
                cout<<"NO"<<endl; 
                return  ;
            }
        }
        m[a]-- ;
    }
    cout<<"YES"<<endl;
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