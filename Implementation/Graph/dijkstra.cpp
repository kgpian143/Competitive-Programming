#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
ll n ,  e ;
const int N = 2e5 + 5 ;
ll INF = 2e15 + 10 ;

vector<pair<ll,ll> > g[N] ;

void dijkstra( ll src )
{
    vector<ll> vis( N , 0 ) ;
    vector<ll> dist( N , INF ) ;
    set<pair<ll, ll> > st ;
    st.insert({ 0 , src }) ;
    dist[src] = 0 ;
    while (st.size() > 0 )
    {
        auto node = *st.begin() ;
        ll v = node.second ;
        st.erase(st.begin()) ; 
        if( vis[v] )continue; 
        vis[v] = 1 ; 
        ll dist1 = node.first ; 
        for( auto child : g[v])
        {
            ll child_v = child.first ;
            ll wt = child.second ;
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
    cin>>n>>e;
    for( ll i = 0 ; i < e ;  i++)
    {
        ll u , v , wt;
        cin>>u>>v>>wt ;
        g[u].push_back({v ,wt}) ;
    }
} 