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
        int n , m ;
        cin>>n>>m ;
        vi x , y ;
        vector<vector<char>> ch ( n + 1 , vector<char> (m+1)) ;
        for( int i = 0 ; i < n ; i++ )
        {
            for( int j = 0 ; j < m ; j++ )
            {
                 cin>>ch[i+1][j+1] ;
                 if( ch[i+1][j+1] == 'B' )x.push_back(i+1) , y.push_back(j+1) ;
            }
        }
        sort( all(x) );
        sort( all(y)) ;
        int a = (x[0] + x[x.size()-1] + 1)/2;
        int b = ( y[0] + y[y.size() - 1])/2 ;
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}