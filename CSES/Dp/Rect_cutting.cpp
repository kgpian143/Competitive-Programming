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
typedef vector<pii> vpii;
int dp[505][505];
// int solve( int a , int b )
// {
//     //  cout<<0<<endl ;
//      if( dp[a][b] != -1)return dp[a][b] ;
//     //  cout<<1<<endl ;
//      if( a == b )return dp[a][b] = 0 ;
//     //  cout<<2<<endl ;
//      if( a == 2*b || b == 2*a )return dp[a][b] = 1 ;
//     //  cout<<3<<endl ;
//      if( a > b )return dp[a][b] = solve(a-b,b) + 1 ;
//     //  cout<<4<<endl ;
//      return dp[a][b] = solve(a,b-a) + 1 ;
// }
int main()
{
    // int t ;
    // cin>>t ;
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
            {
                int ans = 1e8;
                for (int k = 1; k < i; k++)
                {
                    ans = min(ans, 1+ dp[i - k][j] + dp[k][j]);
                }
                for (int k = 1; k < j; k++)
                {
                    ans = min(ans, 1 + dp[i][j - k] + dp[i][k]);
                }
                dp[i][j] = ans;
            }
        }
    }
    cout<<dp[a][b] ;
    return 0;
}