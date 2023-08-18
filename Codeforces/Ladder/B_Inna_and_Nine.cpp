#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define int  long long  
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<int> vl;
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii;
typedef map<int, int> mll;
typedef pair<int, int> pii;  
typedef pair<int, bool> pib; 
typedef pair<int, int> pll; 
typedef unsigned int ull; 
typedef long double ld; 
typedef int ll; 
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;
const int N = 1e5 + 5 ;

void solve()
{
    string s ; 
    cin >> s ;
    int ans = 1 ;
    int k = 0 ; 
    
    for( int i = 1 ; i < s.size() ; i++)
    {
        if( ( s[i] + s[i-1] - '0' - '0' ) == 9 )k++ ;
        else 
        {
            if( ( k & 1 ) == 0 ) ans *= ( k/2 + 1 ) ;
            k = 0 ;  
        }
    }
    if(( k & 1 ) == 0 )ans *=(k/2 + 1 );
    cout << ans << endl ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t = 1; 
    // cin>>t ; 
    while(t-- > 0 )
    {
        solve() ;
    }
    return 0;
}