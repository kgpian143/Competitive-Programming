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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    int car = 0;
    char ch = ( s[0] < '8') ? s[0] + 2 : 1 + '0';
    for (int j = n - 1; j >= 0; j--)
    {
        if (s[j] > ch - car)
        {
            int a = 10 + ch - car - '0' - s[j] + '0';
            car = 1;
            // cout<<a<<" ";
            ans.push_back(a + '0');
        }
        else
        {
            int a = ch - car - (s[j]);
            car = 0;
            // cout<<a<<" ";
            ans.push_back(a + '0');
        }
    }
    reverse(all(ans)) ;
    cout<<ans<<endl;
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