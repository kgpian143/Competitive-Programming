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
int solve( vector<int> A , int B) 
{
    int n = A.size() ;
    int pref[n+1] ;
    pref[0] = 0 ;
    for( int i = 0 ; i < n ; i++ )pref[i+1] = pref[i] + A[i] ;
    int min_sum = INT_MAX ;
    int r = n-B ;
    for( int i = r ; i <= n ; i++ )
    {
        min_sum = min(min_sum , pref[i] - pref[i-r] );
    }
    return pref[n] - min_sum ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n ;
        cin>>n ;
        vi v(n , 0 );
        for( int i = 0 ; i < n ; i++ )cin>>v[i];
        int b ;
        cin>>b ;
        cout<<solve(v , b)<<endl;
    }
    return 0;
}