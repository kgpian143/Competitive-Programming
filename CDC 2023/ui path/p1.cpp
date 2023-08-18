#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define int  long long  
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define aint(v) v.begin() , v.end() 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<int> vl;
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii;
typedef map<int, int> mint;
typedef pair<int, int> pii;  
typedef pair<int, bool> pib; 
typedef pair<int, int> pint; 
typedef unsigned int uint; 
typedef long double ld; 
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;
const int N = 1e5 + 5 ;

int INF = 2e15 + 10 ;

vector<pair<int,int> > g[N] ;

vector<int> dist( N , INF ) ;
map< pair<int , int > , bool > mp ;
void dijkstra( int src , int k  )
{
    vector<int> vis( N , 0 ) ;
    set<pair<pair<int, int> , int > > st ;
    st.insert({{ 0 , src } , 0}) ;
    dist[src] = 0 ;
    while (st.size() > 0 )
    {
        auto node = *st.begin() ;
        int v = node.first.second ;
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
int solve( int nodes , vector<int> from , vector<int> to , vector<int> wgt , int k )
{
    int m = from.size() ;
    for( int i = 0; i < m ; i++)
    {
        g[from[i]].push_back({to[i],wgt[i]}) ;
        g[to[i]].push_back({from[i],wgt[i]}) ;
    }

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ; 
    cin>>t ; 
    while(t-- > 0 )
    {
        solve() ;
    }
    return 0;
}