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

 bool subArrayExists(int arr[], int n)
    {
        //Your code here
        bool ans = false  ;
        multiset<int> st ;
        vector<int> pref( n + 1 , 0 ) ;
        for( int i = 0 ; i < n ; i++ )
        {
            pref[i+1] = pref[i] + arr[i] ;
            if( st.find(pref[i+1]) != st.end())
            {
                ans = true ;
                break;
            }
            st.insert(pref[i+1]);
        }
        return ans ;
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
       int arr[n+1] ; 
       f( i , 0 , n )cin>>arr[i] ;
       if(subArrayExists( arr , n ))cout<<"YES"<<endl ;
       else cout<<"NO"<<endl ;
    }
    return 0;
}