#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
// const int N = 1000005 ;
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
typedef vector<pii> vpii;
long long int dp[1000005][2];

int main()
{ 
    // int dp[100005][2];
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i < 1000005; i++)
    {
        dp[i][0] = ((2*(2 * dp[i - 1][0]) % mod) % mod + (dp[i - 1][1])%mod) % mod;
        dp[i][1] = ((dp[i - 1][0])%mod + (2 * dp[i - 1][1]) % mod) % mod;
    }
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int ans = (dp[n][0] + dp[n][1]) % mod;
        cout << ans << endl;
        // cout<<t;
    }
    return 0;
}