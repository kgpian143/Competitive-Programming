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
    int n ; 
    cin>>n ; 
    vi v1( n , 0 ) ; 
    vi v2( n , 0 ) ; 
    f( i , 0 , n )cin>>v1[i] ; 
    f( i , 0 , n )cin>>v2[i] ;
    sort(all(v1))  ;
    mii m ;
    f( i , 0 , n)
    {
        m[v1[i]]++ ;
    }
    int mx = v1[n-1] ;
    int mn = v1[0] ;
    sort(all(v2))  ;
    f( i , 0 , n )
    {
        int a = v2[i] ; 
        int flag = 0 ;
        while( a >= 1 )
        {
            if( m[a] )
            {
                flag++ ;
                m[a]-- ;
                break ;
            }
             a = a >> 1 ;
        }
        if( flag )continue;
        // /
        a = 1 ;
        while( a <= mx )
        {
            // cout<<1<<endl; 
            if( m[a])
            {
                m[a]-- ;
                flag++ ;
                break ;
            }
            a = a << 1 ;
        }
        if( flag )continue;
        a = v2[i] ; 
        while( a <= mx )
        {
            cout<<2<<endl; 
            if( m[a])
            {
                m[a]-- ;
                flag++ ;
                break ;
            }
            a = a << 1 ;
        }
        if( flag == 0 )
        {
            cout<<"NO"<<endl ;
            return ;
        }
    }
    cout<<"YES"<<endl;
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