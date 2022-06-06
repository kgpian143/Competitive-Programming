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
int t[N] , n , x , sum ;
bool good( int time )
{
    sum = 0 ;
    for( int i = 0 ; i < n ; i++ )
    {
        sum = sum + time/t[i] ;
        if( sum >= x )break ;
    }
    // cout<<sum<<" "<<x<<endl;
    return sum >= x ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    cin>>n>> x ;
    f(i,0,n)cin>>t[i] ;
    int l = 0 ;
    int h = x*(2e9) + 1;
    while( h - l > 1 )
    {
        // cout<<l<<" "<<h<<endl ;
        int m = (l+h)/2  ;
        if(good(m))h = m ;
        else l = m ;
    }
    cout<<h;
    return 0;
}