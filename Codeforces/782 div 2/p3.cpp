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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n ,  ans = 2e18;
    cin>>n ;
    vi v(n) ;
    f(i,0,n)cin>>v[i] ;
    for( int i = 0 ; i < n ; i++ )
    {
        int sum = 0 ,  num = 0  ;
        for( int j = i - 1 ; j >= 0 ; j-- )
        {
            sum += (num / v[j]) + 1 ;
            num = ( num/v[j] + 1)*v[j] ;
        }
        num = 0 ;
        for( int j = i + 1 ; j < n ; j++ )
        {
            sum += (num / v[j]) + 1 ;
            num = ( num/v[j] + 1)*v[j] ;
        }
        // cout<<sum<<endl;
        ans = min(ans , sum);
    }
    cout<<ans;
    return 0;
}