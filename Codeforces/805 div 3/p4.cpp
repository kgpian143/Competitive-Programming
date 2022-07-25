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
    string s ; 
    cin>>s  ; 
    int p ; 
    cin>>p ; 
    map<char  , int > m ; 
    for( int i = 0 ; i < s.size() ; i++ )
    {
        m[s[i]]++ ; 
    }
    int sum = 0 , max_ch = 'z' , cnt = (int)s.size() + 1 ; 
    for( char ch = 'a' ; ch <= 'z' ; ch++ )
    {
        if( sum + m[ch] * ( ch - 'a' + 1 ) >= p )
        {
            max_ch = ch ;
            cnt = ( p - sum )/( ch - 'a' + 1 ) ;
            break ;
        }
        else sum += m[ch] * ( ch - 'a' + 1 ) ;
    }
    int cnt1 = 0 ;
    string ans ;
    for( int i = 0 ; i < s.size() ; i++ )
    {
        if( s[i] < max_ch )ans.push_back(s[i]) ;
        else if( s[i] == max_ch && cnt1 < cnt )
        {
            ans.push_back(s[i]) ;
            cnt1++ ;
        }
    }
    cout<<ans<<endl;
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