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

string nextPermutation(string arr)
{
    int n = arr.size();
    if (n == 1)
        return arr;
    int i = 0;
    for (i = n - 1; i > 0; i--)
    {
        if (arr[i] > arr[i - 1])
            break;
    }
    if (i != 0)
    {
        for (int j = n - 1; j >= i; j--)
        {
            if (arr[i - 1] < arr[j])
            {
                swap(arr[i - 1], arr[j]);
                break;
            }
        }
        reverse(arr.begin() + i, arr.end());
        return arr;
    }
    else
        return "-1";
}

string solve(string s1, string s2)
{
    map<int, int> m;
    for (auto it : s1)
        m[it - '0']++;
    string ans;
    for (int i = 0; i < s2.size(); i++)
    {
        if (m[s2[i] - '0'] > 0)
        {
            m[s2[i] - '0']--;
            ans.push_back(s2[i]);
        }
        else
        {
            for (int i = s2[i] - '0' + 1; i < 10; i++)
            {
                if (m[i] > 0)
                {
                    ans.push_back(m[i] + '0');
                    m[i]--;

                    for (int i = 0; i < 10; i++)
                    {
                        while (m[i]-- > 0)
                            ans.push_back(m[i] + '0');
                    }
                    return ans;
                }
            }
            return "-1";
        }
    }
    return nextPermutation(s1) ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        cout << solve() << endl ;
    }
    return 0;
}