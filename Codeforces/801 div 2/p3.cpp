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

void solve() 
{
    int n , m ;
    cin>>n>>m ;
    int g[n+1][m+1] ;
    f( i , 0 , n )
    {
        f( j , 0 , m)cin>>g[i][j] ;
    }
    set<int> dp[m+1];
    dp[1].insert(g[0][0]) ;
    for( int i = 2 ; i <= m ; i++ )
    {
        dp[i].insert( *(dp[i-1].begin()) + g[0][i-1]) ;
    }
    for( int i = 1 ; i < n ; i++ )
    {
        for( int j = 1 ; j <= m ; j++ )
        {
            set<int> temp ;
            for( auto it : dp[j] )
            {
                temp.insert(it + g[i][j-1]) ; 
            }  
            for( auto it : dp[j-1] )
            {
                temp.insert(it + g[i][j-1]) ; 
            } 
            dp[j].clear() ;
            for( auto it : temp )
            {
                dp[j].insert(it) ;
            }
            temp.clear() ; 
        }
    }
    if( dp[m].find(0) != dp[m].end())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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