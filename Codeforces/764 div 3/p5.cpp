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
    map<string , bool> mp ; 
    map<string , tuple< int , int , int >> data ;
    int n , m ;
    cin>>n>>m ; 
    f( i , 0 , n)
    {
        string s  ;
        cin>>s  ;
        for( int j = 0 ; j < m ; j++ )
        {
            string t ;
            t = s[j] ;
            f( k , 1 , 3 )
            {
                if( k+j >= m )continue; 
                t += s[j+k] ;
                if( !mp[t] )
                {
                    mp[t] = true  ;
                    data[t] = make_tuple( j , j+k , i ) ;
                }
            }
        }
    }
    string s ;
    cin>>s ;
    vector<tuple<int , int , int > > ans ;
    vi dp( m+1 , 0 ) ; 
    dp[0] = 1  ;
    // dp[1]
    for( int i = 2 ; i < m ; i++ )
    {
        if( dp[i-2] )
        {
            string str = s.substr(i-2 , 2 ) ;
            if( mp[str] )ans.push_back(data[str]) ;
        }
        else if( i - 3 >= 0 && dp[i-3] )
        {
            
        }
    }

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