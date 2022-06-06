#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef map<long long, long long> mll;
typedef pair<int, int> pii;  
typedef pair<int, bool> pib;  
typedef pair<long long, long long> pll; 
typedef unsigned long long ull; 
typedef long double ld; 
typedef long long ll; 
typedef vector<vector<int>> vvi; 
typedef vector<pii> vpii; 
const int N = 2e5 + 5 ;
int n ,  e ;
vi g[N] ;
bool vis[N] ;
int par[N] ;
bool bfs(int vertex)
{
    bool ans = false ;
    queue<int> q ;
    q.push(vertex) ;
    vis[vertex] = true ;
    while( !(q.empty()))
    {
        // cout<<1;
        int a = q.front() ;
        q.pop() ;
        if( a == n )
        {
            ans = true ;
            break ;
        }
        for( auto it : g[a])
        {
            if( vis[it])continue;
            par[it] = a ;
            vis[it] = true ;
            q.push(it) ;
        }
    }
    return ans ; 
}
void printpath()
{
    vi v ;
    int a = n ;
    while( a != 1 )
    {
        // cout<<1;
        v.push_back(a) ;
        a = par[a] ;
    }
    v.push_back(1) ;
    reverse(all(v)) ;
    cout<<v.size()<<endl ;
    for( auto it : v) cout<<it<<" ";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    cin>>n>>e ;
    for( int i = 0 ; i < e ;  i++)
    {
        int u , v ;
        cin>>u>>v ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    if( bfs(1))
    {
        printpath();
        // cout<<"POSSIBLE\n";
    }
    else cout<<"IMPOSSIBLE\n";
    return 0;
}