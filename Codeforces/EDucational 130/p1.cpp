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
    int n ,  t ;
    cin>>n>>t ;
    vi v(n , 0) ;
    f( i , 0 , n )
    {
        int a = 0 ;
        cin>>a ;
        v.push_back(-a) ;
    }
    sort(all(v)) ;
    int pref[n+1] ;
    pref[0] = 0 ;
    for( int i = 1 ; i <= n ; i++ )
    {
        pref[i] = pref[i-1] + v[i-1] ;
    }
    while(t-- > 0 )
    { 
        int x  , y ;
        cin>>x>>y ;
        int sum = 0 ;
        sum = pref[x] - pref[x-y] ;
        cout<<-sum<<endl;
    }
    return 0;
}