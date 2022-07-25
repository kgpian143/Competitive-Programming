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
void dfs( int v , int par , vi g[] , vpii & vp , string s)
{ 
    pii p ;
    p.first = 0 ;
    p.second = 0 ;
    for( auto it : g[v] )
    {
        if( it == par)continue; 
        dfs(it , v , g , vp , s ) ;
        p.first += vp[it].first ;
        p.second += vp[it].second ;
    }
    if( s[v-1] == 'W')p.first++ ;
    else p.second++ ;
    vp[v] = p ;
}
void solve() 
{
    int n ;
    cin>>n ;
    vi g[n + 1] ;
    vpii vp( n+1 , { 0 , 0 }) ;
    f( i , 2 , n + 1 ) 
    {
        int a ;
        cin>>a ;
        g[a].push_back(i) ;
        g[i].push_back(a) ;
    }
    string s ;
    cin>>s ;
    dfs( 1 , -1 , g , vp , s  ) ;
    int cnt = -1 ;
    for( auto it : vp )
    {
        if(it.first == it.second)cnt++ ;
    }
    cout<<cnt<<endl;
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