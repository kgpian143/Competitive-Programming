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

bool check( string s  ,  map<string , int > & m )
{
    for( int i = 0 ; i < s.size() ; i++ )
    {
        if( m[s.substr( 0 , i+1) ]   &&  m[s.substr( i + 1)] )
        {
            return true ; 
        }
    }
    return false  ;
}
void solve() 
{
    int n ; 
    cin>>n ; 
    map<string , int > m ; 
    vector<string> vs ; 
    for( int i = 0 ; i < n ; i++ )
    {
        string str  ; 
        cin>>str ;
        m[str]++ ; 
        vs.push_back(str) ; 
    }
    string ans  ;
    for( int i = 0 ; i < n ; i++ )
    {
        if( check( vs[i] , m ))ans.push_back('1') ;
        else ans.push_back('0') ; 
    }
    cout<<ans<<endl ; 
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