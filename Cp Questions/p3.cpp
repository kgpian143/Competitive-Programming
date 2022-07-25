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
    cin>> n ; 
    vi v ( n , 0 ) ;
    // multiset<int> st ;
    mii mp ;
    f( i , 0 , n )
    {
        cin>>v[i] ;
        // st.insert(v[i]) ;
        mp[v[i]]++ ;
    }
    sort(all(v)) ;
    int ans1[n+1] , ans2[n+1] , pref[n+1];
    pref[0] = 0 ;
    f( i , 0 , n )pref[i+1] = pref[i] + v[i] ;
    for( int i = 0 ; i < n ; i++ )
    {
        int ind = v.end() - upper_bound(all(v) , i ) ;
        int ind1 = upper_bound(all(v) , i ) - v.begin();
        // int ind1 = v.end() - upper_bound(all(v) , i ) ;
        ans1[i] = ind ;
        // int ind1 = v.end() - upper_bound()
        int k = n - mp[i] ;
        ans2[i] = n*(k) - ( pref[n] - i*mp[i]) + ind  ;
    }
    for( int i = 0 ; i < n ; i++ )cout<<ans1[i] << " "<<ans2[i] << endl;
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