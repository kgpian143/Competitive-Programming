#include <bits/stdc++.h>
using namespace std;
double P[3005];
double solve(int n)
{
    double dp[n+1][n+1];
    memset(dp,0.0,sizeof(dp));
    dp[0][0] = 1 ;
    for (int k = 1; k <= n; k++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (j == 0)
                dp[k][j] = dp[k - 1][j] * (1.0 - P[k]);
            else
                dp[k][j] = dp[k - 1][j] * (1.0 - P[k]) + dp[k - 1][j - 1] * (P[k]);
        }
    }
   double ans = 0;
    for (int i = (n + 1) / 2; i <= n; i++)
    {
        ans += dp[n][i];
    }
    return ans;
}
int main()
{
    int n;
    // scanf("%d",&n);
    // for (int i = 1; i <= n; i++)
    //     scanf("%lf",&P[i]);
    // // for( int i = 1 ; i <= n ; i++)printf("%.10llf",P[i]);
    // printf("%.10llf",solve(n));
    cin>>n ;
    for( int i = 1 ;  i <= n ; i++)
    {
        cin>>P[i] ;
    }
    cout<<setprecision(10)<<solve(n);
    return 0;
}