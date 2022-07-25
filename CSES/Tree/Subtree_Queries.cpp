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
#define getv(v, n)              \
    for (int i = 0; i < n; i++) \
        cin >> v[i];
#define putv(v)       \
    for (auto it : v) \
        cout << it << ' ';
#define getvv(v, n, m)          \
    for (int i = 0; i < n; i++) \
    f(j, 0, m) cin >> v[i][j]
const int N = 2e5 + 5;
vi g[N];
int pos[N], val[N];
vi v;
int size[N];
void dfs(int u, int p)
{
    int sum = 0;
    v.push_back(u);
    for (auto it : g[u])
    {
        if (it == p)
            continue;
        // depth[v] = depth[u] + 1;
        dfs(it, u);
        sum += size[it] + 1;
    }
    size[u] = sum;
}
class SegmentTree
{
private:
    SegmentTree *left = NULL;
    SegmentTree *right = NULL;
    int st, end, mid;
    bool isOut(int l, int r)
    {
        return (r < st || end < l);
    }
    bool isIn(int l, int r)
    {
        return (l <= st && end <= r);
    }
    int ans;

public:
    SegmentTree(int st1, int end1)
    {
        st = st1;
        end = end1;
        mid = (st + end) >> 1;
    }
    void build(vector<int> &v)
    {
        if (st == end)
        {
            ans = v[st];
            return;
        }
        else
        {
            if (!left)
                left = new SegmentTree(st, mid);
            if (!right)
                right = new SegmentTree(mid + 1, end);
            left->build(v);
            right->build(v);
            ans = (left->ans) + right->ans;
        }
    }
    int getValue(int pos)
    {
        if (st == end)
            return ans;
        if (mid >= pos)
            return left->getValue(pos);
        else
            return right->getValue(pos);
    }
    void update(int i, int v)
    {
        if (st == end)
        {
            ans = v;
            return;
        }
        if (mid >= i)
            left->update(i, v);
        else
            right->update(i, v);
        ans = left->ans + right->ans;
    }
    int getrangesum(int l, int r)
    {
        if (isOut(l, r))
            return 0;
        if (isIn(l, r))
            return ans;
        return left->getrangesum(l, r) + right->getrangesum(l, r);
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    f(i, 0, n)
    {
        cin >> val[i + 1];
    }
    f(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int it =  0 ; it < v.size(); it++)
    {
        pos[v[it]] = it;
    }
    SegmentTree ST(0, n - 1);
    vi  vec( n , 0 ) ;
    for( int i = 0 ; i < v.size() ; i++ )
    {
        vec[i] = val[v[i]] ;
    }
    ST.build(vec);
    // for( int i = 0 ; i < n ; i++ )cout<<v[i]<<" ";
    // cout<<endl;
    // for( int i = 0 ; i < n ; i++ )cout<<pos[v[i]]<<" ";
    // cout<<endl;
    // for( int i = 0 ; i < n ; i++ )cout<<val[i+1]<<" ";
    // cout<<endl;
    while (q-- > 0)
    {
        int t;
        cin >> t;
        if (t == 2)
        {
            int node;
            cin >> node;
            cout << ST.getrangesum(pos[node], pos[node] + size[node]) << endl;
        }
        else
        {
            int node ,  value ;
            cin>>node>>value ;
            ST.update( pos[node] , value );
        }
    }
    return 0;
}