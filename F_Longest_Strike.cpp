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

void solve() 
{
    int n , k ;
    cin>> n >> k ; 
    vi v( n , 0 ) ; 
    mii m ; 
    int max_cnt = 0 ;
    f( i , 0 , n )
    {
        cin>>v[i] ;
        m[v[i]]++ ;
        max_cnt = max( max_cnt , m[v[i]]) ;
    }
    if( max_cnt < k )
    {
        cout<<-1<<endl;
        return ;
    }
    sort(all(v)) ;
    int prev = v[0] ;
    int l1 = -1 , h1 = -1 , l = -1  ,  h  = -1 ;
    for( auto it : m ) 
    {
         if( it.second < k )l1 = -1 ;
         else 
         {
            if( l1 == -1) 
            {
                l1 = it.first ;
                h1 = it.first ;
                if( h1 - l1 >= h - l )
                {
                    h = h1 ;
                    l = l1 ;
                }
            }
            else 
            {
                if( it.first > h1 + 1 )
                {
                    
                    l1 = -1 ;
                }
                else
                {
                     h1++ ;
                     if( h1 - l1 >= h - l ) h = h1 , l = l1 ;
                }
            }
         }
    }
    // if( l == h && l == -1) cout<<-1<<endl;
    cout<<l<<" "<<h << endl ;
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