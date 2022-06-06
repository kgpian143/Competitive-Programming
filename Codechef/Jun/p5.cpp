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
        int n ;
        cin>>n ;
        vi  v( n , 0 ) , p ( n , 0 ) ;
        f(i,0,n)cin>>v[i] ;
        f(i,0,n)
        {
            cin>>p[i] ;
        }
        set<pii> st ;
        int ind = -1 ;
        for( int i = 0 ; i < n ; i++ )
        {
            if( v[i] & 1 )
            {
                st.insert({-p[i] , i});
            }
        }
        int i = 1 ;
        int sum1 = 0 ;
        int sum2 = 0 ;
        while( st.size() > 0 )
        {
            auto it = st.begin() ;
            if( (*it).second < ind )
            {
                st.erase(it) ;
            }
            else 
            {
                if( i & 1 )
                {
                    sum1 += (*it).first;
                    i++ ;
                }
                else 
                {
                    sum2 += ((*it).first) ;
                    i++ ;
                }
                st.erase(it) ;
                ind = (*it).second ;
            }
        }
        cout<<sum2 - sum1 << endl;
    }
    return 0;
}