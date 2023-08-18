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

bool dfs( int u , vi &pos , vpii graph[] )
{
    bool ans = true ;
    for( auto it : graph[u])
    {
        if(pos[it.first] != 1e15)
        {
            // cout << it.first << " ";
            if( pos[u] == (pos[it.first] + it.second ) )continue ; 
            else return false ;
        }
        pos[it.first] = pos[u] - it.second ;
        ans &= dfs( it.first , pos , graph ) ;
    }
    return ans ;
}

void solve()
{
     int n ,  m ; 
     cin >> n >> m ;
     vi a( m+1 , 0 ) , b( m+1 , 0 ) , d(m+1, 0) ;
     vi pos( n+1 , 1e15) ;
     vpii graph[n+1];
     for( int i = 0 ; i < m ; i++)
     {
        cin >> a[i] >> b[i] >> d[i] ;
        graph[a[i]].push_back({b[i] , d[i]});
        graph[b[i]].push_back({a[i] , -d[i]}) ;
     }
     
     for( int i = 1 ; i <=n ; i++)
     {
        if( pos[i] != 1e15) continue;
        pos[i] = 0;
        if( !dfs( i , pos , graph ))
        {
            cout << "NO\n" ;
            return ;
        }
     }
     cout << "YES\n" ;
     
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