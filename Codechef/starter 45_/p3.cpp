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
    vi v( 2*n , 0 ) ;
    vi even ;
    int cnt1 = 0 , cnt2 = 0 ;
    f( i , 0 , 2*n ) 
    {
        cin>>v[i] ;
        if( v[i] & 1) cnt1++ ;
        else 
        {
            cnt2++ ;
            int k = 0 ;
            while( (v[i] & 1) == 0 )
            {
                k++ ;
                v[i] /= 2;
            }
            even.push_back(k) ;
        }
    }
    sort( all(even)) ;
    if( cnt1 >= cnt2 )
    {
        cout<<(cnt1 - cnt2)/2 << endl; 
    }
    else 
    {
        int a = (cnt2 - cnt1)/2 ;
        int ans = 0 ;
        f( i , 0 , a )
        {
            ans += even[i] ;
        }
        cout<<ans<<endl; 
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