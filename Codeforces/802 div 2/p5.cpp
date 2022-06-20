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
#define getv(v,n) for( int i = 0 ; i < n ; i++)cin>>v[i]
#define getvv(v,n,m)for(int i = 0 ; i < n ; i++ )f(j,0 ,m)cin>>v[i][j] 
#define putv(v) for(auto it : v )cout<<it<<' ';
const int N = 2e5 + 5; 
void solve() 
{
    int n , m ;
    cin>>n>>m ;
    vvi v( n , vi(m) ) ;
    getvv(v,n,m) ;
    vpii mvm = {{0 , 1} , { 1 , 0 } , { -1 , 0 } , { 0 , -1} } ;
    vi arr ;
    f( i , 0 , n  )
    {
        f( j , 0 , m )
        {
             if( v[i][j] == 1 )continue ;
             bool ans = false ;
             for( auto it : mvm )
             {
                int a = it.first + i ;
                int b = it.second + j ;
                if( a < 0 && a >= n && b < 0 && b >= m )continue;
                if( v[a][b] < v[i][j] )
                {
                    ans = true ;
                    break ;
                }
             }
             if( !ans )
             {
                 arr.push_back(v[i][j]) ;
             }
        }
    } 
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t = 1;
    // cin>>t ;
    while(t-- > 0 )
    {
        solve();
    }
    return 0;
}