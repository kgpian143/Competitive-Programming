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
const int N = 2e5 + 5, D = 18;
int depth[N], dist[N], val[N], table[32][N] , size[N] , heavy[N] , head[N] , pos[N];
vi vec ;
vi g[N];

void dfs(int u, int p)
{
    // cout<<2 ;
    table[0][u] = p;
    int h_v = 0 ;
    for (int v : g[u])
    {
        if (v == p)
            continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        size[u] += size[v] + 1 ;
        if( size[v] + 1 > size[h_v]) h_v = v ;
    }
    heavy[u] = h_v ;
}
void dfsHld( int v , int h , int par) 
{
    // cout<<1;
    head[v] = h ;
    pos[v] = vec.size() ;
    vec.push_back(val[v]) ;
    if(heavy[v] != 0)dfsHld( heavy[v] , h , v ); 
    for( auto it : g[v] )
    {
        if( it == heavy[v] || it == par )continue;
        dfsHld( it , it , v ) ;
    }
}
int up(int u, int dist)
{
    for (int i = D - 1; i >= 0; i--)
    {
        if ((dist & (1 << i)) > 0)
        {
            u = table[i][u];
            if (u == -1)
                return -1;
        }
    }
    return u;
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
    {
        return lca(v, u);
    }

    int diff = depth[u] - depth[v];
    u = up(u, diff);
    if (u == v)
        return u;

    for (int i = D - 1; i >= 0; i--)
    {
        if (table[i][u] != table[i][v])
        {
            u = table[i][u];
            v = table[i][v];
        }
    }
    return table[0][u];
}

int distance(int u, int v)
{
    int w = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[w];
}
class SegmentTree
{
private:
    SegmentTree *left = NULL;
    SegmentTree *right = NULL;
    int st, end, mid;
    bool isOut(int l, int r)
    {
        return (st > r || end < l);
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
            ans = max(left->ans, right->ans);
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
        ans = max(left->ans, right->ans);
    }
    int getrangemax(int l, int r)
    {
        if (isOut(l, r))
            return INT_MIN;
        if (isIn(l, r))
            return ans;
        return max(left->getrangemax(l, r), right->getrangemax(l, r));
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , q;
    cin >> n >> q;
    f(i, 0, n) cin >> val[i + 1];
    f(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    for (int i = 1; i < D; i++)
    {
        for (int u = 1; u < N; u++)
        {
            if (table[i - 1][u] >= 0)
                table[i][u] = table[i - 1][table[i - 1][u]];
            else
                table[i][u] = -1;
        }
    }
    dfsHld( 1 , 1 , -1);
    SegmentTree ST( 0 , n-1) ;
    ST.build(vec) ;
    // for(  int i  = 1 ; i <= n ; i++ )cout<<vec[i-1]<<" ";
    // cout<<endl;
    // for( int i = 1 ; i <= n ; i++ )cout<<head[i]<<" ";
    // cout<<endl;
    // for( int i = 1 ; i <= n ; i++ )cout<<pos[i]<<" ";
    // cout<<endl;
    while( q-- > 0 )
    {
        int t ;
        cin>>t ;
        if( t == 1 )
        {
            int k , x ;
            cin>>k>>x ;
            ST.update( pos[k] , x ) ;
        }
        else 
        {
            int a  , b ;
            cin>>a>>b ;
            int lca1 = lca( a ,  b  ) ;
            // cout<<"lca : "<<lca1<<endl;
            int mx = INT_MIN ;
            while( head[a] != head[lca1] )
            {
                mx = max( mx , ST.getrangemax( pos[head[a]] , pos[a])) ;
                a = up( head[a] , 1 ) ;
                // cout<<a<<" ";
            }
            mx = max( mx ,  ST.getrangemax( pos[lca1] , pos[a]))  ;
            while( head[b] != head[lca1] )
            {
                mx = max( mx , ST.getrangemax( pos[head[b]] , pos[b])) ;
                b = up( head[b] , 1 ) ;
            }
            mx = max( mx ,  ST.getrangemax( pos[lca1] , pos[b]))  ;
            cout<<mx<<" ";
        }
    }
    return 0;
}