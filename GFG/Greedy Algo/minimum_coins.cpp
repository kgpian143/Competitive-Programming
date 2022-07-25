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

vector<int> minPartition(int N)
    {
        // code here
        int arr[] = { 1 , 2 , 5 , 10 , 20 , 50 , 100 , 200 , 500 , 2000} ;
        vector<pair<int , int >> vp ;
        for( int i = 9 ; i >= 0 ; i++  )
        {
            if( arr[i] > N )continue ;
            int cnt = N / arr[i] ;
            vp.push_back( { arr[i] , cnt }) ;
            N = N % arr[i] ;
            if( N == 0 )break ;
        }
        vector<int> ans  ;
        for( int i = 0 ; i < vp.size() ; i++ )
        {
            while( vp[i].second-- > 0 )ans.push_back(vp[i].first) ;
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
        // solve();
        int n ;
        cin>>n ;
        vi  v = minPartition(n) ;
    }
    return 0;
}