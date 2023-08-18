#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define int  long long  
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<int> vl;
typedef vector<vector<int>> vvl; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii;
typedef map<int, int> mll;
typedef pair<int, int> pii;  
typedef pair<int, bool> pib; 
typedef pair<int, int> pll; 
typedef unsigned int ull; 
typedef long double ld; 
typedef int ll; 
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;
const int N = 1e5 + 5 ;

int dfs( int v , vi &dist , vi graph[] )
{
    int ans = 0  ; 
    for( auto it : graph[v])
    {
        if( dist[it] != -1 )
        {
            if( ( dist[v] - dist[it] + 1 ) & 1 )return 1 ; 
            else continue;
        }
        dist[it] = dist[v]+ 1 ;
        ans += dfs(it , dist , graph) ;
    }
    return ans ; 
}
void solve()
{
    int n ,m ; 
    cin >> n >> m ; 
    vi rg[n+1] , bg[n+1];
    set< pair< int , int > > edges ;
    for( int i = 0 ; i < m ; i++)
    {
        int u , v ;
        cin >> u >> v ; 
        rg[u].push_back(v);
        rg[v].push_back(u) ;
    }

    vi dist( n +1 , -1 ) ;
    int ans = 0 ;
    for( int i = 1 ; i <= n ; i++ )
    {
        if( dist[i] != -1 )continue;
        dist[i] = 0 ; 
        ans += dfs( i , dist , graph );
    }
    if(( n - ans ) & 1)ans++ ;
    cout << ans << "\n" ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t = 1 ; 
    // cin>>t ; 
    while(t-- > 0 )
    {
        solve() ;
    }
    return 0;
}