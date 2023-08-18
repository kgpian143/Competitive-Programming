#include <bits/stdc++.h>
using namespace std;
#define mod 1000000009
#define int long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<int> vl;
typedef vector<vector<bool>> vvb;
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
const int N = 1e5 + 5;

int binaryexp( int n , int k )
{
    int ans = 1 ;
    while( k > 0 )
    {
        if( k & 1 )
        {
            ans = (ans*1LL*n)%mod ;
        }
        n = (n*1LL*n)%mod ;
        k >>= 1 ;
    }
    return ans;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    int a = n-m ;
    int ans = ( n - m ) * ( k - 1 ) ;

    if( ans >= m )
    {
        cout << m << endl ; 
        return ;
    }

    int b = m - ans ; 
    int q = b / k ;
    ans += b % k ;

    int sum = binaryexp( 2 , q ) ;
    sum = ( sum - 1 ) * k * 2 ;

    ans = ( ans + sum )%mod ;
    cout << ans << endl ;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t-- > 0)
    {
        solve();
    }
    return 0;
}