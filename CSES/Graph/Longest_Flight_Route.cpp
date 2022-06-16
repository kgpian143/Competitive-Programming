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
int n , e ;
vi g[N] ;
bool vis[N] ;
int child[N] ;
int level[N] ;

void dfs( int v )
{
     vis[v] = true ;
     for( auto it : g[v]) 
     {
        if( level[it] < level[v] + 1 )
        {
            child[it] = v ;
            level[it] = level[v] + 1 ;
            vis[it] = true ;
            if( it != n )dfs(it) ;
        }   
     }
}
void dfs1( int v )
{
     vis[v] = true ;
     if( v == n )return  ;
     for( auto it : g[v]) 
     {
         if( !vis[it] )dfs1(it) ;
         if( level[it] == 0)continue ;
         if( level[v] < (level[it] + 1)) 
         {
            level[v] = level[it] + 1 ;
            child[v] = it ;
         }   
     }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>n >> e ;
    f( i , 0 , e )
    {
        int u , v ;
        cin>>u>>v ;
        g[u].push_back(v) ;
    }
    level[n] = 1 ;
    dfs1(1);
    // f( i , 0 , n )cout<<child[i+1]<<" ";
    if( vis[n] )
    {
        cout<<level[1]<<endl;
        vi ans ;
        int node = 1 ;
        while( node != n )
        {
            // cout<<1 ;
            ans.push_back(node) ;
            node = child[node] ;
        }
        ans.push_back(n) ;
        // reverse(all(ans)) ;
        for( auto it : ans )cout<<it<<" ";
    }
    else cout<<"IMPOSSIBLE";
    return 0;
}