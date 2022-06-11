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
const int N = 3e5 + 5;
vi graph[N];
bool vis[N];
int ele[N];
void dfs(int vertex)
{
    vis[vertex] = true;
    int sum = 0;
    for (auto child : graph[vertex])
    {
        if (vis[child])continue;
        dfs(child);
        // cout<<1 ;
        sum = sum + ele[child];
    }
    ele[vertex] = sum + 1;
}
int getmaxsave(int vertex)
{
    if (ele[vertex] == 1)
        return 0;
    if( graph[vertex].size() == 1 ) return ele[vertex] - 2;
    // int m1 = ele[graph[vertex][1]] - 1  + getmaxsave(graph[vertex][0]);
    // int m2 = ele[graph[vertex][0]] - 1 + getmaxsave(graph[vertex][1]);
    // return max(m1, m2);
    else 
    {
        int ans = -1 ;
        for( auto it : graph[vertex])
        {
            if( ele[it] > ele[vertex])continue;
            if( ele[it] + 1 == ele[vertex])return  ele[it] - 1 ;
            else 
            {
                 int m = ele[vertex] - ele[it] - 2 + getmaxsave(it) ;
                 ans = max( m , ans );
            }
        }
        return ans ;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, e;
        cin >> n ;
        // graph.resize(n+1) ;
        for (int i = 0; i < n-1; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // cout<<1;
        dfs(1) ;
        // for( int i = 0 ; i < n ; i++ )cout<<ele[i+1]<<" ";
        cout<<getmaxsave(1)<<endl ;
         for(int i = 0 ; i < N ; i++ )
        {
            graph[i].clear() ;
            vis[i] = false ;
            ele[i] = 0 ;
        }
    }

    return 0;
}