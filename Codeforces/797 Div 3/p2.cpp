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
        int n , k = -1 , flag = 0 , flag1 = 0  ;
        cin>>n ;
        vi v(n) , v1(n) ;
        int c = -2;
        f(i,0 ,n)cin>>v[i] ;
        f( i , 0 , n )cin>>v1[i] , c = max( c , v[i] - v1[i]) ;
        for( int i = 0 ; i < n ; i++ )
        {
            if( c < 0 )
            {
                flag++ ;
                break;
            }
            if( c != v[i] - v1[i] && v1[i] != 0 )
            {
                flag++ ;
                break;
            }
        }
        if(flag)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}