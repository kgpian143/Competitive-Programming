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
int n, m;
const int N = 1005;
char g[N][N];
bool vis[N][N];
int grid[N][N];
char path[N][N];
pii parent[N][N];
vpii monst;
pii dest;
bool vis1[N][N];
int steps[N][N];
bool isvalid(int i, int j)
{
    if (vis[i][j])
        return false;
    if (i < 1 || j < 1)
        return false;
    if (i > n || j > m)
        return false;
    if (g[i][j] == '#')
        return false;
    return true;
}
bool isvalid1(int i, int j)
{
    if (vis1[i][j])
        return false;
    if (i < 1 || j < 1)
        return false;
    if (i > n || j > m)
        return false;
    if (g[i][j] == '#')
        return false;
    return true;
}
vpii mvmt;
void bfs1()
{
    // cout<<2 ;
    queue<pii> q;
    for (auto it : monst)
    {
        q.push(it);
        vis1[it.first][it.second] = true;
        grid[it.first][it.second] = 0;
    }
    while (!(q.empty()))
    {
        // cout<<1;
        pii a = q.front();
        q.pop();
        int i = a.first;
        int j = a.second;
        for (auto it : mvmt)
        {
            int i1 = i + it.first;
            int j1 = j + it.second;
            if (isvalid1(i1, j1))
            {
                q.push({i1, j1});
                grid[i1][j1] = grid[i][j] + 1;
                vis1[i1][j1] = true;
            }
        }
    }
}
bool bfs(pii src)
{
    queue<pii> q;
    q.push(src);
    vis[src.first][src.second] = true;
    steps[src.first][src.second] = 0;
    while (!q.empty())
    {
        pii a = q.front();
        q.pop();
        int i = a.first;
        int j = a.second;
        if (i == 1 || i == n || j == 1 || j == m)
        {
            if( vis1[i][j] == false )
            {
                dest.first = i;
                dest.second = j;
                return true ;
            }
            else if (steps[i][j] < grid[i][j] )
            {
                dest.first = i;
                dest.second = j;
                return true;
            }
            else
                continue;
        }
        if (isvalid(i + 1, j))
        {
            path[i + 1][j] = 'D';
            parent[i + 1][j] = {i, j};
            vis[i + 1][j] = true;
            steps[i + 1][j] = 1 + steps[i][j];
            q.push({i + 1, j});
        }
        if (isvalid(i - 1, j))
        {
            path[i - 1][j] = 'U';
            vis[i - 1][j] = true;
            q.push({i - 1, j});
            steps[i - 1][j] = 1 + steps[i][j];
            parent[i - 1][j] = {i, j};
        }
        if (isvalid(i, j + 1))
        {
            path[i][j + 1] = 'R';
            vis[i][j + 1] = true;
            steps[i][j + 1] = 1 + steps[i][j];
            q.push({i, j + 1});
            parent[i][j + 1] = {i, j};
        }
        if (isvalid(i, j - 1))
        {
            path[i][j - 1] = 'L';
            vis[i][j - 1] = true;
            steps[i][j - 1] = 1 + steps[i][j];
            q.push({i, j - 1});
            parent[i][j - 1] = {i, j};
        }
    }
    return false;
}
void printpath(pii st)
{
    string s;
    int i = dest.first;
    int j = dest.second;

    while (make_pair(i, j) != st)
    {
        s.push_back(path[i][j]);
        int t1 = i;
        int t2 = j;
        i = parent[t1][t2].first;
        j = parent[t1][t2].second;
    }
    reverse(all(s));
    cout << s.size() << endl;
    cout << s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    mvmt.push_back({1, 0});
    mvmt.push_back({-1, 0});
    mvmt.push_back({0, 1});
    mvmt.push_back({0, -1});
    cin >> n >> m;
    pii st;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'A')
            {
                st.first = i;
                st.second = j;
            }
            if (g[i][j] == 'M')
            {
                monst.push_back({i, j});
            }
        }
    }
    bfs1();
    if (bfs(st))
    {
        cout << "YES\n";
        printpath(st);
    }
    else
        cout << "NO\n";
    return 0;
}