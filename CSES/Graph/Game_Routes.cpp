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
vi g[N] , par[N] ;
int dp[N] ;
int n ,  e ;
int routes( int k )
{
    if( dp[k] != -1) return dp[k] ;
    int sum = 0 ;
    for( auto it : par[k] )
    {
        sum = (sum + routes(it))%mod ;
    }
    return dp[k] = sum ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    memset(dp, -1 , sizeof(dp)) ;
    dp[1] = 1 ;
    cin>>n>>e ;
    f( i , 0 , e) 
    {
        int u , v ;
        cin>>u>>v ;
        par[v].push_back(u) ;
    }
    int k = routes(n) ;
    cout<<k;
    return 0;
}