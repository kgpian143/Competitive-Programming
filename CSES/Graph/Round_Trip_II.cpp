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
int n, e;
vi g[N];
vi ans;
bool vis[N], rstack[N];
stack<int> st;
bool dfs(int vertex)
{
    vis[vertex] = true;
    rstack[vertex] = true;
    st.push(vertex);
    for (auto child : g[vertex])
    {
        if (!vis[child])
        {
            if (dfs(child))
                return true;
        }
        if (rstack[child])
        {
            st.push(child);
            return true;
        }
    }
    st.pop();
    rstack[vertex] = false;
    return false;
}
void printcycle()
{
    int src = st.top();
    ans.push_back(src);
    st.pop();
    while (st.top() != src)
    {
        ans.push_back(st.top());
        st.pop();
    }
    ans.push_back(src);
    cout << ans.size() << endl;
    reverse(all(ans));
    for (auto it : ans)
        cout << it << " ";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> e;
    bool ans1 = false;
    f(i, 0, e)
    {
        int u, v;
        cin >> u >> v ;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        if (dfs(i))
        {
            ans1 = true;
            printcycle();
            break;
        }
    }
    if (!ans1)
        cout << "IMPOSSIBLE";
    return 0;
}