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
const int N = 1e5 + 5; 
int bit[N][32] ;
int solution( vector<int> &A , vector<int> &B  )
{
    int n = A.size() ; 
    int m = B.size() ; 
    sort(A.begin() , A.end() ) ;
    sort(B.begin() , B.end() ) ;
    int sum1 = accumulate( A.begin() , A.end() , 0 ) ;
    int sum2 = accumulate( B.begin() , B.end() , 0 ) ;
    int cnt = 0 ;
    for( int i = 0 ; i < n ; i++ )
    {
        if( abs( 6 - A[i] ) + sum1 >= sum2 ) 
        {
            cnt++ ; 
            return cnt  ;
        }
        sum1 += abs( 6 - A[i]) ;
        cnt++ ;
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