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
    vi v( n , 0 );
    vi ans( n+1 , 0 ) ;
    mii mp ;

    for( int i = 0 ; i < n ; i++)
    {
        cin >> v[i];
        mp[v[i]]++ ;
    }

    for( auto it : mp )
    {
        int a = it.first ;
        int b = it.second ;

        for( int i = a ; i <= n ; i += a )
        {
            ans[i] += b ;
        }
    }
    int res = *max_element( all(ans)) ;
    cout << res << "\n";
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