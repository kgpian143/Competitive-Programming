#include<bits/stdc++.h>
using namespace std ;
#define int long long 
int n ,  e ;
const int N = 2e5 + 5 ;
int INF = 2e15 + 10 ;
vector<int> dist( N , INF ) ;
vector<pair<int,int> > g[N] ;

void dijkstra( int src )
{
    vector<int> vis( N , 0 ) ;
    set<pair<int, int> > st ;
    st.insert( { 0 , src } ) ;
    dist[src] = 0 ;
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
            if( dist[v] + wt  < dist[child_v])
            {
                dist[child_v] = dist[v] + wt ;
                st.insert({ dist[child_v] , child_v}) ;  
            } 
        }
    }
    
}
signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    // int n ,  e ;
    cin>>n>>e ;
    for( int i = 0 ; i < e ;  i++)
    {
        int u , v , wt;
        cin>>u>>v>>wt ;
        g[u].push_back({v ,wt}) ;
        // g[v].push_back({u ,wt}) ;
    }
    dijkstra(1) ;
    for( int i =  1 ; i <= n ; i++ )
    {
        cout<<dist[i]<<" ";
    }
} 