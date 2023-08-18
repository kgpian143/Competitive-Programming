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

int indp[N][2][2];
int outdp[N][2][2] ;

void dfs( int v , int p , vi graph[] , int m )
{
    indp[v][0][1] = 0 ;
    indp[v][0][0] = 1 ;
    indp[v][1][0] = 0 ;
    indp[v][1][1] = 1 ;  // subtree contain black node , current node is black 

    for( auto ch : graph[v])
    {
        if( ch == p)continue; 
        dfs(ch , v , vi , m);
        indp[v][0][1] = ( indp[v][0][1] + indp[ch][0][1] + indp[ch][1][1] ) % m ; 
        indp[v][1][1] = ( indp[v][1][1] ) * ( indp[ch][1][1] + indp[0][0] ) ;
        indp[v][1][1] %= m ;
    }
}

void dfs( int v , int p , vi graph[] , int m )
{
    if( p == 0 )
    {
        outdp[v][0][1] = 0 ;
        outdp[v][1][1] = 0 ;
        outdp[v][1][0] = 0 ;
        outdp[v][0][0] = 0 ;
    }
    else 
    {
        outdp[v][1][0]
    }
}
void solve()
{
    int n ,m ;
    cin >> n >> m ;
    
    vi graph[n+1];
    for( int i = 0 ; i < n - 1 ; i++ )
    {
        int u , v ;
        cin >> u >> v ;
        graph[u].push_back(v);
        graph[v].push_back(u);
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