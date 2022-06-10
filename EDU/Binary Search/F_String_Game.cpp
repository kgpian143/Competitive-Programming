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
int n ;
vi  v ;
string s  , t ;
bool good( int x )
{
    string s1 = s ;
    for( int i = 0 ; i < x ; i++ )
    {
        s1[v[i] - 1] = ' ' ;
    }
    int j = 0 ;
    for( int i = 0  ; i < n ; i++ )
    {
        if(s1[i] == t[j] )
        {
            j++ ;
            if( j == t.size())break;
        }
    }
    if( j == t.size())return true ;
    else return false ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    // int n ;
    // cin>>n ;
    cin>>s>>t ;
    n = (int)s.size() ;
    v.resize(n) ;
    f(i,0,n)cin>>v[i] ;
    int l = -1 ;
    int r = s.size() - t.size() + 1; 
    while( r - l > 1 )
    {
        int m  = ( l + r)/2 ;
        if( good(m))l = m ;
        else r = m ;
    }
    cout<<l<<endl;
    return 0;
}