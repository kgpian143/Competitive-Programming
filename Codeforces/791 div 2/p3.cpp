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
int row[N] ;
int col[N] ;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n , q ;
    cin>>n>>q ;
    // vb rows( n + 1 , false ) ;
    // vb colums( n + 1, false ) ;
    ordered_set stx , sty ;
    while(q-- > 0 )
    {
        int t  ;
        cin>>t ;
        if( t == 1 )
        {
             int x , y ;
             cin>>x>>y ;
             if( row[y] == 0 )sty.insert(y) ;
             if( col[x] == 0 )stx.insert(x) ;
             row[y]++ ;
             col[x]++ ;
        }
        else if( t == 2 )
        {
            int x  , y ;
            cin>>x>>y ;
            row[y]-- ;
            col[x]-- ;
            if( row[y] == 0 )sty.erase(sty.find(y)) ;
            if( col[x] == 0 )stx.erase(stx.find(x)) ;
        }
        else 
        {
            int x1 , y1 , x2 , y2 ;
            cin>>x1>>y1>>x2>>y2 ;
            int flag = 0 ,  flag1 = 0 ;
            cout<<stx.order_of_key(x1)<<" "<<stx.order_of_key(x2)<<endl;
            cout<<sty.order_of_key(y1)<<" "<<sty.order_of_key(y2)<<endl;
            if( stx.find(x1) != stx.end() && stx.find(x2) != stx.end())
            {
                if( x2 - x1 == (stx.order_of_key(x2) - stx.order_of_key(x1)) )flag++ ;
            }
            if( sty.find(y1) != sty.end() && sty.find(x2) != sty.end())
            {
                if( y2 - y1 == (sty.order_of_key(y2) - sty.order_of_key(y1)) )flag1++ ;
            }
            // if( stx.order_of_key(x1) != x1 - 1 || stx.order_of_key(x2) != x2 - 1 )flag++ ;
            // if( sty.order_of_key(y1) != y1 - 1 || sty.order_of_key(y2) != y2 - 1 )flag1++ ;
            if( flag == 1 || flag1 == 1 )cout<<"Yes"<<endl ;
            else cout<<"No"<<endl ;
        }
    }
    return 0;
}

