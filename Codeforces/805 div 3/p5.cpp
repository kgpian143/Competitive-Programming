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
bool dfs( int v , int par ,  vb &vis , vi g[] , int h )
{
    vis[v] = true  ;
    bool ans = true  ; 
    if( g[v].size() != 2  )return false  ;
    for( auto it : g[v] )
    {
        if( vis[it] )
        {
            if( it != par  )
            { 
                if( h & 1 )return false  ;
                else return true  ;
            }
            else continue;
        }
        return dfs( it , v , vis  , g , h+1 ) ; 
    }
    return ans  ;

}
void solve() 
{
    int n ; 
    cin>>n ; 
    vi g[n+1] ;
    f( i , 0 , n )
    {
        int u , v ; 
        cin>>u>>v ; 
        g[u].push_back(v) ; 
        g[v].push_back(u) ; 
    } 
    vb vis( n +1 , false ) ;
    for( int i = 1  ; i <= n ; i++ )
    {
        if( vis[i] )continue; 
        if( !dfs( i , -1 , vis , g , 1 ) )
        {
            cout<<"NO"<<endl;
            return  ;
        }
    }
    cout<<"YES"<<endl; 
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        solve();
    }
    return 0;
}