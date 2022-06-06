#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define f(i, a, b) for (int i = a; i < b; i++)
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<vector<bool>> vvb;
typedef map<int, int> mii;
typedef map<long long, long long> mll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef vector<vector<int>> vvi;
#define max_ INT_MAX - 100
int main()
{
    int n;
    cin >> n;
    int dp[n + 1];
    // int m = n;

    // dp[]
    dp[0] = 0;
    f(i, 1, n + 1)
    {
        int a = 0;
        int val[7];
        int m = i;
        while (m > 0)
        {
            val[a++] = m % 10;
            m = m / 10;
        }
        dp[i] = max_;
        f(j, 0, a)
        {

            if (val[j] > i)
                continue;
            dp[i] = min(dp[i], 1 + dp[i - val[j]]);
        }
    }
    cout << dp[n];
    return 0;
}