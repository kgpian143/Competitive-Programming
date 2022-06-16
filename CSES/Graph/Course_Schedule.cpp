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
int n ,  e  ;
vi  g[N]  ,  ans ;
int vis[N] , rs[N] ;
stack<int> st ;
bool dfs( int v )
{
    vis[v] = true ;
    rs[v] = true ;
    st.push(v) ;
    for( auto it : g[v])
    {
        if( !vis[it] )
        {
            if( dfs(it))return true ;
        } 
        if( rs[it] ) 
        {
            return true ;
        }
    }
    rs[v] = false ;
    st.pop() ;
    ans.push_back(v) ;
    return false ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    cin>>n>>e ;
    bool ans1 = false ;
    f( i , 0 , e )
    {
        int u ,  v ;
        cin>>u>>v ;
        g[v].push_back(u) ;
    }
    for( int i = 1 ; i <= n ; i++ )
    {
        if( vis[i] )continue; 
        if(dfs(i))
        {
            ans1 = true  ;
            cout<<"IMPOSSIBLE";
            break;
        }
    }
    if(!ans1 )for( auto it : ans )cout<<it<<" ";
    return 0;
}