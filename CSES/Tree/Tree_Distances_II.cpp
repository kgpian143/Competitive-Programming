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
int ele[N] ;
int dist[N] ;
int par[N] ;
void dfs( int v , int par )
{
    int num = 0 ;
    for( auto it : g[v])
    {
        if( it == par)continue; 
        depth[it] =  depth[v] + 1 ;
        dfs(it , v ) ;
        num += ele[it] + 1;
    }
    ele[v] = num ;
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
        // par[v] = u ;
    }
    dfs( 1 , -1 );
    f( i , 1 , n + 1)
    {
         dist[1] += depth[i] ;
    }
    stack<int>  st ;
    st.push(1) ;
    // int parent = -1 ;
    while( !st.empty())
    {
        int a  = st.top() ;
        st.pop() ;
        // cout<<1<<parent;
        for( auto it : g[a] )
        {
            if( it == par[a] )continue;
            dist[it] = dist[a] - ele[it] + n - ele[it] - 2;
            par[it] = a ;
            st.push(it) ;
        }
        // pa
    }
    for( int i =  1  ; i <= n ; i++ )cout<<dist[i]<<" ";
    return 0;
}