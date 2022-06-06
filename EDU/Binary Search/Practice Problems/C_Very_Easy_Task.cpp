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
typedef vector<vector<bool>> vvb;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<pii> vpii;
int x, y, n;
bool good(int a)
{
    return (a / x) + (a / y) >= n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x >> y;
    if (n < 2)
    {
        cout << min(x, y) << endl;
    }
    else
    {
        n = n - 1;
        int l = 0;
        int r = 2e9;
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            if (good(m))
                r = m;
            else
                l = m;
        }
        cout << r +  min(x, y);
    }
    return 0;
}