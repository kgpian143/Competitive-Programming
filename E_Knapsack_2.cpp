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
    int n, w;
    cin >> n >> w;
    vi wgt(n, 0), val(n, 0);
    vector<vi> dp(n + 1, vi(1e5 + 5, INT_MAX));

    for (int i = 0; i < n; i++)
    {
        cin >> wgt[i];
        cin >> val[i];
    }

    int ans = -1;
    dp[0][0] = 0 ;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= 1e5; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (val[i - 1] > j)
                continue;

            dp[i][j] = min(dp[i][j], dp[i - 1][j - val[i - 1]] + wgt[i - 1]);
            if (i == n)
            {
                if (dp[i][j] <= w )ans = j ; 
            }
        }
    }
    cout << ans << endl;
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