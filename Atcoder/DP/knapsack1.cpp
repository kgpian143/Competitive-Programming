#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int w[105], v[105];
 int dp[105][N];
int solve( int k, int n)
{
    if (dp[n][k] != -1)
        return dp[n][k];
    if (n == 0 || k == 0)
    {
        return dp[0][0] = 0;
    }

    if (k >= w[n - 1])
    {
        //  int k1 = solve(k, n - 1) ;
        //  int k2 = v[n-1]+ solve(k - w[n - 1], n - 1) ;
        //  int p ;
        // if( k1 > k2 )p = k1 ;
        // else p = k2 ;
        return dp[n][k] = max(solve(k, n - 1), v[n - 1] + solve(k - w[n - 1], n - 1));
    }
    else
        return dp[n][k] = solve(k, n - 1);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, wt;
    cin >> n >> wt;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    cout << solve(wt, n);
    return 0;
}