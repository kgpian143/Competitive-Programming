#include<bits/stdc++.h>
using namespace std ;
#define int long long 
int n ,  e ;
const int N = 2e5 + 5 ;
int INF = 2e17 + 10 ;
vector<int> dist( N , INF ) ;
vector<pair<int,int> > g[N] ;

void dijkstra( int src )
{
    auto comp =  [](pair<int, pair<int ,int>> a , pair<int, pair<int ,int>> b) 
    {
        if(a.first != b.first )return a.first < b.first ;
        else if( a.second.first != b.second.first)return a.second.first < b.second.first ;
        else return a.second.second < b.second.second ;
    };
    vector<int> vis( N , 0 ) ;
    set<pair<int, pair<int ,int>> , decltype(comp)>st ;
    st.insert({ 0 , { 1 , 0 }}) ;
    dist[src] = 0 ;
    while (st.size() > 0 )
    {
        auto node = *st.begin() ;
        int v = node.second.first ;
        int mx_dist = node.second.second ;
        st.erase(st.begin()) ; 
        if( vis[v] )continue; 
        vis[v] = 1 ; 
        int dist1 = node.first ; 
        for( auto child : g[v])
        {
            // cout<<1;
            int child_v = child.first ;
            int wt = child.second ;
            if( dist[v] + wt  < dist[child_v]  || dist[v] + wt/2 + (mx_dist + 1)/2 < dist[child_v])
            {
                // cout<<2;
                // dist[child_v] = dist[v] + wt ;
                // st.insert({ dist[child_v] , child_v}) ;  
                if( wt > mx_dist )
                {
                    dist[child_v] = dist[v] + ( mx_dist + 1)/2 + wt/2 ;
                    st.insert( { dist[child_v] , {child_v , wt}}) ;
                }
                else 
                {
                    dist[child_v] = dist[v] + wt ;
                    st.insert( { dist[child_v] , {child_v , mx_dist}}) ;
                }
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
    dijkstra(1) ;
    // cout<<dist[n];
    for( int i = 0 ; i < n ; i++ )
    {
        cout<<dist[i+1]<<" ";
    }
} 