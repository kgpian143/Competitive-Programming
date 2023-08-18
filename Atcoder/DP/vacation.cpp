#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
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
typedef vector<vector<int>> vvl;
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

void solve()
{
    int n;
    cin >> n;
    vector<vi> v(n, vi(3, 0));
    vector<vi> dp(n+1, vi(3, 0));
    f(i, 0, n)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    int prev_ind = -1 , curr_ind = -1;
    for( int i = 1 ; i <= n ; i++ )
    {
        dp[i][0] = max( dp[i-1][1] , dp[i-1][2]) + v[i-1][0] ;
        dp[i][1] = max( dp[i-1][0] , dp[i-1][2]) + v[i-1][1] ;
        dp[i][2] = max( dp[i-1][1] , dp[i-1][0]) + v[i-1][2] ;
    }
    int ans = 0 ; 
    for( auto it : dp[n])
    {
        ans = max( ans , it ) ;
    }
    cout << ans << endl ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin>>t ;
    while (t-- > 0)
    {
        solve();
    }
    return 0;
}