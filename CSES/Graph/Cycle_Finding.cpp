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
int dist[N];
int par[N];
void bellman_ford()
{
    int x = -1;
    for (int i = 1; i <= n; ++i)
    {
        x = -1;
        for (auto e : edges)
        {
            int u = e.first.first;
            int v = e.first.second;
            int d = e.second;
            if (dist[u] + d < dist[v])
            {
                dist[v] = d + dist[u];
                par[v] = u;
                x = v;
            }
        }
    } // n relaxations
    if( x == -1)
    {
        cout<<"NO"<<endl;
        return ;
    }
    for( int i = 1  ; i <= n ; i++ )
    {
        x = par[x] ;
    }
    cout<<"YES"<<endl;
    vi ans ;
    ans.push_back(x) ;
    int k = par[x] ;
    while( k != x )
    {
        ans.push_back(k) ;
        k = par[k] ;
    }
    ans.push_back(k) ;
    reverse(all(ans)) ;
    for( auto it : ans )cout<<it<<" ";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    // dist.resize(n + 1);
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
}