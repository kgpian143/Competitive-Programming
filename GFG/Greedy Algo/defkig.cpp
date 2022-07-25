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
    int n , w  , h  ;
    cin>>w>>h>>n ;
    vi x( n, 0 ) , y ( n , 0 ) ;
    f( i , 0 , n )
    {
        cin>>x[i]>>y[i] ;
    }
    x.push_back(0) ;
    x.push_back(w + 1) ;
    y.push_back(0) ;
    y.push_back(h + 1) ;
    int d1 = 0 , d2 = 0 ;
    sort( all(x) );
    sort( all(y) );
    for( int i = 1 ; i <= n + 1 ; i++ )
    {
        d1 = max( d1 , x[i] - x[i-1] - 1) ;
        d2 = max( d2 , y[i] - y[i-1] - 1) ;
        // cout<<d1<<" "<<d2<<endl;
    }
    cout<<d1*d2<<endl;
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