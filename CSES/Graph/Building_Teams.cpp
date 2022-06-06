#include <bits/stdc++.h>
using namespace std;
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
vi graph[N];
bool vis[N];
int par[N];
int team[N] ;
bool dfs(int vertex)
{
    bool ans = true;
    vis[vertex] = true;
    for (auto it : graph[vertex])
    {
        if (vis[it])
        {
            if (team[it] == team[vertex])
            {
                return false;
            }
            else
                continue;
        }
        team[it] = (team[vertex] + 1) % 2;
        ans &= dfs(it);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // vi cities ;
    bool ans = true;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        team[i] = 1;
        ans &= dfs(i);
    }
    if (ans)
    {
        for (int i = 1; i <= n; i++)
        {
            if( team[i] == 0 )cout<<2<<" ";
            else cout<<1<<" ";
        }
    }
    else cout<<"IMPOSSIBLE\n" ;
    return 0;
}