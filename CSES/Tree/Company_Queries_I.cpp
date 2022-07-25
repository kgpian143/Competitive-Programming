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
#define getv(v,n) for( int i = 0 ; i < n ; i++)cin>>v[i];
#define putv(v) for(auto it : v )cout<<it<<' ';
#define getvv(v,n,m)for(int i = 0 ; i < n ; i++ )f(j,0 ,m)cin>>v[i][j] 
const int N = 2e5 + 5; 
int dp [32][N] ;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n , q   ;
    cin>>n >> q;
    dp[0][1] = -1 ;
    for( int i = 1 ; i < 33 ; i++ )dp[i][1] = -1 ;
    for( int i = 2 ; i <= n ; i++ )
    {
        int a ;
        cin>>a ;
        dp[0][i] = a ;
    }
    for( int i = 1 ; i < 32 ; i++ )
    {
        for( int j = 1 ; j <= n ; j++ )
        {
            if( dp[i-1][j] == -1) dp[i][j] = -1 ;
            else dp[i][j] = dp[i-1][dp[i-1][j]] ;
        }
    }
    while( q-- > 0 )
    {
        int a  , b  ;
        cin>>a>>b ;
         for( int i = 32 ; i >= 0 ; i-- )
        {
            if( a == -1)break; 
            if( (b & ( 1LL << i )) > 0 )
            {
                // cout<<i
                a = dp[i][a] ;
                // cout<<a;
            }
        }
        cout<<a<<endl;
    }
    return 0;
}