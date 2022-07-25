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
    int n, k;
    cin >> n >> k;
    map<int, pii> m;
    for (int a = 0; a < n; a++)
    {
        int i;
        cin >> i;
        if (m[i].first == 0)
        {
            m[i].first = a + 1;
            m[i].second = a + 1;
        }
        else
        {
            m[i].first = min(m[i].first, a + 1);
            m[i].second = max(m[i].second, a + 1);
        }
    }
    while (k-- > 0)
    {
        int a, b;
        cin >> a >> b;
        if (m[a].first == 0 || m[b].first == 0)
            cout << "NO" << endl;
        else if (m[a].first < m[b].second)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
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