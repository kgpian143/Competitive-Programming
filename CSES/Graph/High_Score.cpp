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
typedef vector<pll> vpll;
int n, e;
const int N = 2e5 + 5;
ll INF = 2e15 + 10;
vpll g[N];
vl score(N, -INF);
vb vis(N, false);
bool dijkstra(int src)
{
    bool ans = false;
    set<pll> st;
    score[src] = 0;
    st.insert({0, src});
    while (st.size() > 0)
    {
        // cout<<2;
        pll a = *st.begin();
        st.erase(st.begin());
        ll v = a.second;
        if (vis[v])
            continue;
        vis[v] = true;
        for (auto child : g[v])
        {
            // cout<<3;
            ll child_v = child.first;
            ll wt = child.second;
            if (score[v] + wt > score[child_v])
            {
                score[child_v] = score[v] + wt;
                st.insert({-score[child_v], child_v});
            }
        }
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        g[u].push_back({v, wt});
    }
    if (dijkstra(1))
    {
        cout<<score[n] ;
    }
    cout<<score[n] ;
}