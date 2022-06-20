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
        vi v(n , 0 ) ;
        f( i , 0 , n )cin>>v[i] ;
        int sum = 0 ;
        int ind = 0 ;
        for( int i = 0 ; i < n ; i++ )
        {
            sum += v[i] ;
            if( v[i] != 0 )ind = i ;
        }
        if( sum != 0 || v[ind] > 0 )cout<<"NO"<<endl;
        else 
        {
            int flag = 0 ;
            int val = 0 ;
            for( int i = 0 ; i < ind ; i++ )
            {
                val = val + v[i] ;
                if( val <= 0 )
                {
                    flag++ ;
                    break ;
                }
            }
            if( flag == 0)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}