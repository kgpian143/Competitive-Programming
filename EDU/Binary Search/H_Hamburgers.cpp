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
string str ; 
int cnt1 , cnt2 , cnt3 ;
pii s , b , c ;
int r ;
bool good( int x )
{
    int mn = 0 ;
    int i = max( x*cnt1 - s.first , mn ) ;
    int j = max(x*cnt2 - b.first , mn ) ;
    int k = max(x*cnt3 - c.first , mn);
    // cout<<i<<" "<<j<<" "<<k<<endl;
    int cost ;
    cost = i*s.second + j*b.second + k*c.second ;
    return r >= cost ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    cin>>str ;
    cin>>b.first>>s.first>>c.first ;
    cin>>b.second>>s.second>>c.second ;
    cin>>r ;
    for( int i = 0 ; i < str.size() ; i++ )
    {
        if( str[i] == 'B')cnt2++ ;
        else if( str[i] == 'S')cnt1++ ;
        else cnt3++ ;
    }
    int l = -1 ;
    int r = 1e15 ;
    while( r - l > 1 )
    {
        int m = (r+l)/2 ;
        if(good(m)) l = m ;
        else r = m ;
    }
    cout<<l;
    return 0;
}