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
int n, k;
int pref[N];
vi v(N, 0);
bool good(int x)
{
    for (int i = x; i < n; i++)
    {
        if (pref[i] - pref[i - x] == k)
            return true;
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        cin >> n >> k;
        int sum = 0;
        f(i, 0, n)
        {
            cin >> v[i];
            pref[i + 1] = pref[i] + v[i];
        }
        if (pref[n] < k)
            cout << -1 << endl;
        else if (pref[n] == k)
            cout << 0 << endl;
        else
        {
            int l = 0, h = 1e8;
            while (h - l > 1)
            {
                int m = (h + l) / 2;
                if (good(m))
                    l = m;
                else
                    h = m;
            }
            cout << n - l << endl;
        }
    }
    return 0;
}