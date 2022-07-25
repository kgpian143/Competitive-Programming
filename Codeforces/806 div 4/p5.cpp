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
    int n ; 
    cin>> n  ; 
    char g[n+1][n+1] ; 
    vvi vis( n + 1 ,  vi( n + 1 , 0 )) ; 
    map< pii , pii > m ; 
    int cnt = 0 ; 
    f( i , 0 , n )
    {
        f( j , 0 , n )cin>>g[i][j] ; 
    }
    f( i , 0 , n )
    {
        f( j , 0 , n )
        {
            if( vis[i][j] )continue ; 
            else 
            {
                int cnt0 = 0 ; 
                int cnt1 = 0 ; 
                int i1 = i , j1 = j ; 
                if( g[i1][j1] == '0')cnt0++ ; 
                else cnt1++ ; 
                for( int i = 0 ; i < 3  ; i++ )
                {
                    int temp = i1 ; 
                    i1 = j1  ; 
                    j1 = n - 1  - temp ; 
                    vis[i1][j1]++ ; 
                    if( g[i1][j1] == '0')cnt0++ ; 
                    else cnt1++ ;
                }
                cnt += min( cnt0 , cnt1 ) ; 
            }
        }
    }
    cout<<cnt<<endl ; 
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