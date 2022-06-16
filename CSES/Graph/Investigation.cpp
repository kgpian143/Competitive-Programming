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
// typedef unsigned int uint; 
typedef long double ld; 
typedef vector<pii> vpii; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define aint(v) v.begin() , v.end()
struct Node 
{
    // int level ;
    int max_level ;
    int min_level ;
    int count_path ;
};
const int N = 2e5 + 5; 
const int INF = 2e18 ;
vector<pii>  g[N] ;
int n , e ;
Node nodes[N] ;
vector<int> vis( N , 0 ) ;
vector<int> price( N , INF ) ;
// vi ans[N] ;
void dijkstra( int src )
{
    set<pair<int, int> > st ;
    st.insert({ 0 , src }) ;
    price[src] = 0 ;
    while (st.size() > 0 )
    {
        auto node = *st.begin() ;
        int v = node.second ;
        st.erase(st.begin()) ; 
        if( vis[v] )continue; 
        vis[v] = 1 ; 
        int dist1 = node.first ; 
        for( auto child : g[v])
        {
            int child_v = child.first ;
            int wt = child.second ;
            if( price[v] + wt  < price[child_v])
            {
                price[child_v] = price[v] + wt ;
                nodes[child_v].max_level  = nodes[v].max_level + 1 ;  
                nodes[child_v].min_level  = nodes[v].min_level + 1 ;  
                nodes[child_v].count_path  = nodes[v].count_path  ;  
                st.insert({ price[child_v] , child_v}) ;  
            }
            else if( price[v] + wt == price[child_v] )
            {
                nodes[child_v].max_level  = max(nodes[v].max_level + 1  , nodes[child_v].max_level);  
                nodes[child_v].min_level  = min(nodes[v].min_level + 1 , nodes[child_v].min_level) ;  
                nodes[child_v].count_path  = (nodes[v].count_path + nodes[child_v].count_path ) %mod ;
            } 
        }
    }
    
}
signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    cin>>n>>e;
    for( int i = 0 ; i < e ;  i++)
    {
        int u , v , wt;
        cin>>u>>v>>wt ;
        g[u].push_back({v ,wt}) ;
    }
    nodes[1].count_path = 1 ;
    nodes[1].max_level = 1 ;
    nodes[1].min_level = 1 ;
    dijkstra(1) ;
    cout<<price[n]<<" "<<nodes[n].count_path<<" "<<nodes[n].min_level - 1 <<" "<<nodes[n].max_level - 1 ;
} 