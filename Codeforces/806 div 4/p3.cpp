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
    cin>>n ; 
    vi v( n , 0 ) ; 
    f( i , 0 , n )cin>>v[i] ; 
    f( i , 0 , n )
    {
        int k ; 
        cin>> k ; 
        string s  ; 
        cin>>s ; 
        for( int j = s.size() - 1 ; j >= 0 ; j--  )
        {
            if( s[j] == 'D')
            {
                v[i] = ( v[i] + 1) % 10 ; 
            }
            else 
            {
                v[i] = ( v[i] + 9 ) % 10 ;  
            }
        }
    }
    for( auto it : v )cout<<it<<" "; 
    cout<<endl ; 
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