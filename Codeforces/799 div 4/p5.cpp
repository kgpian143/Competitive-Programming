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
// int pref[n], suff[n];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        vi v(n, 0);
        int sum1 = 0;
        f(i, 0, n)
        {
            cin >> v[i];
            sum1 += v[i] ;
        }
        if( sum1 < k  )
        {
            cout<<-1<<endl;
            continue;
        }
        int i = 0, j = 0, sum = 0;
        int maxLen = INT_MIN;
        while (j < n)
        {
            sum += v[j];
            if (sum < k)
            {
                j++;
            }
            else if (sum == k)
            {
                maxLen = max(maxLen, j - i + 1);
                j++;
            }
            else if (sum > k)
            {
                while (sum > k)
                {
                    sum -= v[i];
                    i++;
                }
                if (sum == k)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
                j++;
            }
        }
        cout<<n - maxLen<<endl;
    }
    return 0;
}