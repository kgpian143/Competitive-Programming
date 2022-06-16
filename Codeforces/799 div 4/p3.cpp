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
        char ch[8][8] ;
        f( i , 0 , 8 )
        {
            f( j , 0 , 8)cin>>ch[i][j] ;
        }
        int a , b ;
        f( i , 1 , 7 )
        {
            f( j , 1 , 7) 
            {
                if( ch[i][j] == '#' && ch[i-1][j-1] == '#' && ch[i+1][j+1] == '#' && ch[i+1][j-1] && ch[i-1][j+1] == '#' )
                {
                    a = i+1 ;
                    b = j+1 ;
                }
            }
        }
        cout<<a<<" "<<b <<endl;

    }
    return 0;
}