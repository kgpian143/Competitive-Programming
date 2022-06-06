#include <bits/stdc++.h>
using namespace std;
 
// #define TEST(a) cout<<"Case #"<<a<<": ";
#define int long long
// #define ll long long
// #define Uint unsigned int
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define pb push_back
#define mii map<int, int>
#define INF 10000000
#define take(a) \
    int a;      \
    cin >> a;
#define MOD 1000000007
#define pii pair<int, int>
#define MAX_N 7532
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 1000000;
    vector<vi> dp(n + 1, vi(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = ((4 * dp[i - 1][0]) + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] + (2 * dp[i - 1][1])) % MOD;
    }
    take(tc);
    while (tc--)
    {
        take(val);
        cout << (dp[val][0] + dp[val][1]) % MOD << "\n";
    }
    return 0;
}