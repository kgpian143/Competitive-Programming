#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
#define f(i, a, b) for (int i = a; i < b; i++)
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<vector<bool>> vvb;
typedef map<int, int> mii;
typedef map<long long, long long> mll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef pair<long long, long long> pll;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;
const int N = 2e5 + 5;
const int inf = 1e12 + 10;

int dist[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = inf;
        }
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        dist[x][y] = wt;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return 0;
}