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
vi g[N];
int pos[N], val[N];
int ans[N] ;
vi vec;
int size[N];
void dfs(int u, int p)
{
    cout<<1 ;
    int sum = 0;
    vec.push_back(u);
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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n ;
    f(i, 0, n)
    {
        cin >> val[i + 1];
    }
    f( i , 0 , n )cout<<val[i+1] << " " ;
    f(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int it =  0 ; it < vec.size(); it++)
    {
        pos[vec[it]] = it;
    }
    // SegmentTree ST(0, n - 1);
    vi  v1( n , 0 ) ;
    // for( int i = 0 ; i < vec.size() ; i++ )
    // {
    //     v1[i] = val[vec[i]] ;
    // }
    set<int> st ;
    for( int i = n - 1 ; i >= 0 ; i-- )
    {
        st.clear() ;
        while( i > i - size[vec[i]] - 1)
        {
            cout<<1;
            st.insert(val[vec[i]]) ;
            ans[vec[i]] = st.size() ;
            i-- ;
        }

        i++ ;
    }
    for( int i = 1 ; i <= n ; i++ )cout<<ans[i] << " ";
    return 0;
}