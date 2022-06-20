#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<vector<bool>> vvb;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<pii> vpii;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define mod 1000000007
#define f(i, a, b) for (int i = a; i < b; i++)
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
const int N = 2e5 + 5;

void solve()
{
    int n, m;
    cin >> n >> m;
    // vvi  v( n + 1 ,  vi( m + 1 , 0 ));
    // vvi  dp( n + 1 ,  vi( m + 1 , 0 ));
    // int dp[n + 1][m + 1];
    // memset(dp, 0, sizeof(dp));
    int sum = 0 ;
    for (int i = 1; i <= m; i++)
    {
        sum += i ;
    }
    for( int j = 2 ; j <= n ; j++ )sum += (j*m);
    cout << sum << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
    return 0;
}