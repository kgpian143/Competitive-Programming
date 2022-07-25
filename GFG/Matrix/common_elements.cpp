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
// #define getvv(v,n,m)for(int i = 0 ; i < n ; i++ )f(j,0 ,m)cin>>v[i][j] 
const int N = 2e5 + 5; 

void solve( vvi  v  , int n , int m ) 
{
    mii mp ;
    // m[0] = 1 ;
    f( i , 0 , n)
    {
        f( j , 0 , m )
        {
            mp[v[i][j]]++ ;
        }
    }
    vi  ans ;
    for( auto it : mp )
    {
        if( it.second == n )ans.push_back(it.first) ;
    }
    for( auto it : ans )cout<<it<<" ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n , m ;
        cin>>n>>m ;
        vvi  v( n , vi(m)) ;
        f( i , 0 , n )
        {
            f( j , 0 , m )cin>>v[i][j] ;
        }
        solve(v , n , m);
    }
    return 0;
}