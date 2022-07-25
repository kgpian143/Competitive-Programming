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
#define getv(v,n) for( int i = 0 ; i < n ; i++)cin>>v[i];
#define putv(v) for(auto it : v )cout<<it<<' ';
#define getvv(v,n,m)for(int i = 0 ; i < n ; i++ )getv( v[i] , m );
const int N = 2e5 + 5; 

int median(vector<vector<int>> &mat, int r, int c){
        // code here    
        int min_ele = mat[0][0] , max_ele = mat[0][c-1]  ;
        f( i , 0 , r )
        {
            min_ele = min( mat[i][0] , min_ele) ;
            max_ele = max( mat[i][c-1] , max_ele ) ;
        } 
        int l = min_ele , h = max_ele ;
        while( h - l > 1 )
        {
           
            int m = ( l + h ) /2 ;
            int cnt = 0 ;
            f( i , 0 , r )
            {
                cnt += lb( all(mat[i]) , m) - mat[i].begin() ;
                // cout<<cnt<<" ";
            }
            if( cnt == (r*c) / 2) return m  ;
            else if( cnt < (r*c)/2 ) l = m ;
            else h = m ;
            //  cout<<l<<" "<<h<<" "<<cnt<<endl;
        } 
        return h ;
    }
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int r ,  c ;
        cin>>r>>c ;
        vvi mat( r  , vi(c) ) ;
        // getvv( mat , r  , c ) ;
        // getv( mat[i] , c );
        // putv( mat[i] , c );
        f( i , 0 , r)f( j , 0 , c )cin>>mat[i][j] ;
        int med = median( mat , r , c );
        cout<<med<<endl;
    }
    return 0;
}