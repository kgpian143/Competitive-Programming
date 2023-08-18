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
typedef vector<vector<int>> vvl; 
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
    int n ;
    cin >> n ;
    mii m1 , m2 , m3 , m4 ;

    for( int i = 0 ; i < n ; i++)
    {
        int x , y ;
        cin >> x >> y ;
        m1[x]++;
        m2[y]++ ;
        m3[x+y]++;
        m4[x-y]++ ;
    }
    int ans = 0 ;
    for( auto it : m1 )
    {
        ans += ( it.second - 1 ) *( it.second ) ;
    }
    for( auto it : m2 )
    {
        ans += ( it.second - 1 ) *( it.second ) ;
    }
    for( auto it : m3 )
    {
        ans += ( it.second - 1 ) *( it.second ) ;
    }
    for( auto it : m4 )
    {
        ans += ( it.second - 1 ) *( it.second ) ;
    }
    cout << ans << '\n' ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ; 
    cin>>t ; 
    while(t-- > 0 )
    {
        solve() ;
    }
    return 0;
}