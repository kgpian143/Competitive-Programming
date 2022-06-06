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
int bit[32] ;
void cal( int k )
{
    int j = 1 ;
    while( k > 0 )
    {
        if( k % 2 )bit[j]++ ;
        k = k/2 ;
        j++ ; 
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
        int n ;
        cin>>n ;
        vi  v (n , 0 );
        vpii ans ;
        f(i,0,n)
        {
            cin>>v[i] ;
            cal(v[i]) ;
        }
        // if( n == 2 )
        // {
        //     if( v[0] & v[])
        // }
        int flag = 0 ;
        int ind ;
        
        for( int i = 1 ; i <= 32 ; i++ )
        {
            if(bit[i] > 1 )
            {
                flag++ ;
                ind = i ;
                break;
            }
        }
        if( flag == 0 )cout<<"NO\n";
        else 
        {
            cout<<"YES\n";
            int sum = 0 , ind1 = 0 , ind2 = 0 ;
            for( int i = 0 ; i < n ;i++ )
            {
                sum += v[i] ;
                if( sum & ( 1 << (ind-1)))
                {
                    ans.push_back( {ind1 + 1 , ind2 + 1} ) ;
                    ind1 = i + 1 ;
                    ind2++ ;
                    sum = 0 ;
                }
                else ind2++ ;
                if((bit[ind] - ans.size()) % 2 == 1 && ans.size() != 0 )
                {
                    ans.push_back( {ind1 + 1 , n} );
                    break;
                }
            }
            cout<<ans.size()<<endl;
            for( auto it : ans )cout<<it.first<<" "<<it.second<<endl;
        }

    }
    return 0;
}