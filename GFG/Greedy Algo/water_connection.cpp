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
vector<pair<int , int>> g[N] ;
int par[N] ;
bool vis[N] ;
int  dfs( int v , int &d )
{
    vis[v] = true ; 
    if( g[v].size() == 0 )return v ;
    d = min( g[v][0].second , d) ;
    return dfs( g[v][0].first , d ) ;
}
vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        for( int i = 0 ; i < p ; i++ )
        {
            g[a[i]].push_back({ b[i] , d[i] } ) ;
            // g[b[i]].push_back(a[i]) ;
            par[b[i]] = a[i] ; 
        }
        vector<vector<int>> ans ;
        for( int i = 1 ; i <= n ; i++ )
        {
            if( par[i] == 0 )
            {
                int d = INT_MAX ;
                int t = dfs( i , d ) ;
                vector<int> v( 3 , 0 ) ;
                v[0] = i ;
                v[1] = t ;
                v[2] = d ;
                ans.push_back(v) ;
            }
        }
        return ans ;
    }
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        // solve();
    }
    return 0;
}