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
int inv( vi &v , int l , int r  )
{
    // cout<<1;
    int n = r - l  ;
    if( n == 1 )return 0 ;
    int m = ((l+r)/2) ;
    int cnt = 0 ;
    cnt = inv( v , l , m ) + inv( v , m , r) ;
    // for( int i = l ; i < r ; i++)cout<<v[i]<<" ";
    // cout<<endl;
    for( int i = l , j = m   ; i < m && j < r ; j++ )
    {
        if( v[j] < v[i])
        {
            cnt = cnt + m - i ;
        }
        if( v[i] <= v[j] )i++ , j--;
    }
    // cout<<endl;
    sort( v.begin() + l , v.begin() + r ) ;
    // for( int i = l ; i < r ; i++)cout<<v[i]<<" ";
    // cout<<cnt<<endl;
    return cnt ;
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
        vi v(n,0) ;
        f( i , 0 , n )cin>>v[i] ;
        cout<<inv(v , 0 , n ) << endl;
    }
    return 0;
}