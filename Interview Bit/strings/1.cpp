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

int solve(string A) {
    // int mod = 1e9 + 7 ;
    int n = A.size() ;
    int count_vow[n+1] , count_cons[n+1] ;
    count_vow[0] = 0 ;
    count_cons[0] = 0 ;
    for( int i = 0 ; i < n ; i++ )
    {
        if( A[i] == 'a' || A[i] == 'e' ||  A[i] == 'i' || A[i] == 'o'||  A[i] == 'u' )
        {
            count_vow[i+1] = count_vow[i] + 1 ;
            count_cons[i+1] = count_cons[i] ;
        }
        else 
        {
            count_vow[i+1] = count_vow[i] ;
            count_cons[i+1] = count_cons[i] + 1 ;
        }
    }
    int ans = 0 ;
    for( int i = 0 ; i < n ; i++  )
    {
        if( A[i] == 'a' || A[i] == 'e' ||  A[i] == 'i' || A[i] == 'o'||  A[i] == 'u' ) 
        {
            ans = (ans + count_cons[n] - count_cons[i] ) % mod ; 
        }
    }
    return ans  ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        string s  ;
        cin>>s ;
        int a = solve(s);
        cout<<a<<endl;
    }
    return 0;
}