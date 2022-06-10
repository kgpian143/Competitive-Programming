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
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n , k;
        cin>>n>>k ;
        int pref[n+1] ;
        pref[0] = 0 ;
        string s ;
        cin>>s ;
        f( i , 0 , n )
        {
            if( s[i] == 'B')pref[i+1] = pref[i] + 1 ;
            else pref[i+1] = pref[i] ;
        }
        int mx = pref[k] - pref[0]  ;
        for( int i = 1 ; i <= n - k ; i++ )
        {
            mx = max( mx , pref[k+i] - pref[i]) ;
        }
        cout<<k-mx<<endl;
    }
    return 0;
}