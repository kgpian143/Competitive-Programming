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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vi v(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        map<int, vi> m;
        for (int i = 0; i < n; i++)
        {
            m[v[i]].push_back(i);
        }
        int l, r, max_profit = INT_MIN , a ;
        for (auto it : m)
        {
            int st, end, profit = INT_MIN , ind = 0 ;
            vi arr;
            arr.push_back(1);
            for (int i = 1; i < it.second.size(); i++)
            {
                arr.push_back(-1 * (it.second[i] - it.second[i - 1] - 1));
                arr.push_back(1);
            }
            int curr_sum = 0;
            for (int i = 0; i < arr.size(); i++)
            {
                if (curr_sum + arr[i] > profit)
                {
                    // cout<<1;
                    profit = curr_sum + arr[i];
                    st = ind;
                    end = i;
                }

                if (curr_sum + arr[i] <= 0)
                {
                    // ind = i ;
                    curr_sum = 0;
                }
                if (curr_sum == 0 && arr[i] == 1)
                    ind = i;
                curr_sum += arr[i];
            }
            // cout<<profit<<" ";
            if (profit > max_profit)
            {
                l = it.second[st / 2];
                r = it.second[end / 2];
                max_profit = profit;
                a = it.first ;
            }
        }
        cout<<a<<" "<<l+1<<" "<<r+1<<endl;
    }
    return 0;
}