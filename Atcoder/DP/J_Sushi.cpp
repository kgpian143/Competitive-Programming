#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 301, one = 1;
int n;
long double dp[N][N][N];
typedef long double ld;

void solve()
{
    int n;
    cin >> n;
    int ones = 0, twos = 0, threes = 0;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if (val == 1)
            ones++;
        else if (val == 2)
            twos++;
        else if (val == 3)
            threes++;
    }

    dp[0][0][0] = 0 ;
    for (int i = 0; i <= threes; i++)
    {
        for (int j = 0; j <= twos + threes; j++)
        {
            for (int k = 0; k <= n; k++)
            {

                ld z = n - i - j - k;
                ld o = k, tw = j, th = i;

                if( z == n )continue; 
                long double ans = 1;
                if (k)
                {
                    ans += (dp[i][j][k - 1]) * (o / n );
                }
                if (j)
                {
                    ans += (dp[i][j - 1][k + 1]) * (tw / (n));
                }
                if (i)
                {
                    ans += (dp[i - 1][j + 1][k]) * (th / n );
                }
                dp[i][j][k] = ans / ( 1 - z / n  );
            }
        }
    }
    cout << dp[threes][twos][ones] << endl;
}

int main()
{
    cout << setprecision(10) << fixed;
    solve();
    return 0;
}