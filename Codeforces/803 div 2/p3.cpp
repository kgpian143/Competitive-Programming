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
    vi v( n , 0 ) ;
    f( i , 0 , n )cin>>v[i] ; 
    mii m ; 
    f( i , 0 , n )m[v[i]] = 1  ;
    int cnt = 0 , ele1 = 0 , ele2 = 0  ;
    if( n == 3 )
    {
        int cnt1 = 0 , cnt2 = 0 , sum = 0 ;
        f( i , 0 , n  )
        {
            sum += v[i] ;
            if( v[i] > 0 ) cnt1++ ;
            else if( v[i] < 0 )cnt2++ ;
        }
        if( cnt1 + cnt2 == 3 && m[sum] == 1 )
        {
            cout<<"YES"<<endl;
            return ;
        }
    }
    if( n == 4 )
    {
        int sum = 0 , cnt = 0 ; 
        for( int i = 0 ; i < n ; i++ )
        {
            sum += v[i] ;
            if( v[i] == 0 )
            {
                cnt++ ;
                break ;
            }
        }
        if( cnt == 0 )
        {
            int f = 0 ;
            for( int i = 0 ; i < n ; i++ )
            {
                 if( m[sum-v[i]] == 0 )
                 {
                    f++ ;
                    break ;
                 }
            }
            if( f == 0 )
            {
                cout<<"YES"<<endl;
                return ;
            }
        }
    }
    f( i , 0 , n )
    {
        if( v[i] != 0 )
        {
            if( ele1 == 0 )
            ele1 = v[i] ;
            else ele2 = v[i] ;
            cnt++ ;
        }
    }
    if( cnt < 2  || (cnt == 2 && ele1 + ele2 == 0 ))
    {
        cout<<"YES"<<endl;
        return ;
    }
    cout<<"NO"<<endl;
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