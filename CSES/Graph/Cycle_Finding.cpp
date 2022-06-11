#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<vector<bool>> vvb;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<pii> vpii;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define mod 1000000007
#define f(i, a, b) for (int i = a; i < b; i++)
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
const int N = 2e5 + 5;
const int INF = 1e17;
const int NINF = INF * (-1);

int n, m;
vector<pair<pii, int>> edges;
vector<int> dist;
int par[N], root;
void bellman_ford()
{
    for (int i = 1; i < n; ++i)
    {
        for (auto e : edges)
        {
            int u = e.first.first;
            int v = e.first.second;
            int d = e.second;
            cout<<dist[u]<<" "<<dist[v]<<" "<<d<<endl;
            if (dist[u] == INF)
                continue;
            dist[v] = min(dist[v], d + dist[u]);
            dist[v] = max(dist[v], NINF);
        }
    } // n relaxations

    for (int i = 1; i < n; ++i)
    {
        for (auto e : edges)
        {
            // cout<<2;
            int u = e.first.first;
            int v = e.first.second;
            int d = e.second;
            // cout<<dist[u]<<" "<<dist[v]<<" "<<d<<endl;
            if (dist[u] == INF)
                continue;
            dist[v] = max(dist[v], NINF);
            if (dist[u] + d < dist[v])
            {
                cout<<1;
                dist[v] = NINF;
                if (root == 0)
                    root = u;
                par[v] = u;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    dist.resize(n + 1);
    edges.resize(m);
    for (int i = 0; i < m; ++i)
    {
        pair<pii, int> inp;
        cin >> inp.first.first >> inp.first.second >> inp.second;
        // inp.second *= -1;
        edges[i] = inp;
    }
    dist[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        dist[i] = INF;
    }

    bellman_ford();
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == NINF)
        {
            cout << "YES" << endl;
            vi ans;
            ans.push_back(root);
            int node = par[root];
            while (node != root)
            {
                ans.push_back(node);
                node = par[node];
            }
            ans.push_back(node);
            reverse(all(ans));
            for (auto it : ans)
                cout << it << " ";
            return 0;
        }
    }
    cout << "NO" << endl;
}