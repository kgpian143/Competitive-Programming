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
int n , k ;
vi v ;
bool good( int x )
{
    int total = x*k ;
    for( int i = 0 ; i < n ; i++ )
    {
        total -= min(x , v[i] ) ;
        if( total <= 0 )return true ;
    }
    return false ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    cin>> k >> n;
    v.resize(n) ;
    f(i,0,n)cin>>v[i] ;
    int l = -1 ;
    int h = 1e17 ;
    while( h - l > 1) 
    {
        int  m = ( l + h )/ 2 ;
        if(good(m)) l = m ;
        else h = m ;
        // cout<<l<<" "<<h<<end/l;
    }
    cout<<l;
    return 0;
}