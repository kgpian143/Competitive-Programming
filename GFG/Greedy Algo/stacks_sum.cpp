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

int greater1( int a , int b , int c )
{
    if( a == b && b == c )return 0 ;
    int mx = max( a , b ) ;
    mx = max( mx  , c) ;
    if( mx == a) return 1 ;
    if( mx == b )return 2  ;
    else return 3 ;
}
int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int sum1 =  accumulate( all(S1) , 0 * 1LL  ) ;    
        int sum2 =  accumulate( all(S2) , 0 * 1LL  ) ;    
        int sum3 =  accumulate( all(S3) , 0 * 1LL  ) ; 
        int i = 0 , j = 0 , k = 0 ;
        while(1)
        {
            if( greater1( sum1 , sum2 , sum3 ) == 0 )return sum1;
            else 
            {
                int ans = greater1( sum1 , sum2 , sum3 ) ;
                if( ans == 1 )
                {
                    sum1 -= S1[i++] ;
                    if( sum1 == 0 )return 0 ;
                }
                else if( ans == 1 )
                {
                    sum2 -= S2[j++] ;
                    if( sum2 == 0 )return 0  ;
                }
                else 
                {
                    sum1 -= S3[k++] ;
                    if( sum3 == 0 )return 0;
                }
            }
        }   
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