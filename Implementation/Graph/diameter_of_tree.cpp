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
#define getvv(v,n,m)for(int i = 0 ; i < n ; i++ )f(j,0 ,m)cin>>v[i][j] 
const int N = 2e5 + 5; 
vi g[N] ;
int depth[N] ;
void dfs( int v , int par )
{
    for( auto it : g[v])
    {
        if( it == par)continue; 
        depth[it] = depth[v] + 1 ;
        dfs(it , v ) ;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n ;
    cin>>n ;
    f( i , 0 , n -1 )
    {
        int u ,  v ;
        cin>>u>>v ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    dfs( 1 , -1 );
    int max_depth = -1 ;
    int max_node = 1 ;
    for( int i = 1 ; i <= n ; i++ )
    {
        if( max_depth < depth[i] )
        {
            max_node = i ;
            max_depth = depth[i] ;
        }
        depth[i] = 0 ;
    }
    dfs( max_node , -1) ;
    for( int i = 1 ; i <= n ; i++ )
    {
        if( max_depth < depth[i] )
        {
            // max_node = i ;
            max_depth = depth[i] ;
        }
        // depth[i] = 0 ;
    }
    cout<<max_depth<<endl;
    return 0;
}