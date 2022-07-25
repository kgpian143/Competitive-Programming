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

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int , int >> vp ;
    for( int i = 0 ; i < n ; i++ )
    {
        vp.push_back({ end[i] , start[i]}) ;
    }
    sort( vp.begin() , vp.end()) ;
    int cnt = 1 , ind = 0  ;
    for( int i = 1 ; i < n ; i++ )
    {
        if( vp[i].second >= vp[ind].first )
        {
            cnt++ ;
            ind = i ; 
        }
    }
    return cnt ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        // solve();
    }
    return 0;
}