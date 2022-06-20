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

vector<vector<int>> stockBuySell(vector<int> A, int n)
{
    vector<vector<int>> ans;
    int st = -1;
    vector<int> buy, sell;
    int b_value, s_value;
    for (int i = 0; i < n; i++)
    {
        if (st == -1 && A[i + 1] >= A[i] && i != n - 1)
        {
            st = i;
            b_value = A[i];
        }
        if (st != -1)
        {
            if (A[i] <= b_value)
            {
                st = i;
            }
            else
            {
                int j = st;
                while (A[st] == A[j])
                    j--;
                j++;
                while (A[j + 1] == A[st])
                {
                    buy.push_back(j);
                    sell.push_back(i);
                    j++;
                }
                buy.push_back(st);
                sell.push_back(i);
            }
        }
    }
    ans.push_back(buy);
    ans.push_back(sell);
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        vi v;
        int n;
        cin >> n;
        v.resize(n);
        f(i, 0, n) cin >> v[i];
        vvi v1;
        v1 = stockBuySell(v, n);
        for (int i = 0; i < 2; i++)
        {
            for (auto it : v1[i])
                cout << it << " ";
            cout << endl;
        }
    }
    return 0;
}