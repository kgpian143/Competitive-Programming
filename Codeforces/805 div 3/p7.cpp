#include<bits/stdc++.h>
using namespace std ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long 
typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef pair<int, int> pii;  
typedef pair<int, bool> pib;  
typedef unsigned long long ull; 
typedef long double ld; 
typedef vector<pii> vpii; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
#define getv(v,n) for( int i = 0 ; i < n ; i++)cin>>v[i];
#define putv(v) for(auto it : v )cout<<it<<' ';
#define getvv(v,n,m)for(int i = 0 ; i < n ; i++ )f(j,0 ,m)cin>>v[i][j] 
// const int N = 2e5 + 5; 

struct LCA
{

    int N;
    static const int D = 18;
    vector<vector<int>> table;
    vector<vector<int>> tree;
 
    vector<int> depth;
 
    LCA(vector<vector<int>>  &tree)
    {
        N = tree.size() ;
        this->tree = tree;
        depth.assign(N, 0);
        table.assign(D, vector<int>(N, -1));
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
    }
 
    void dfs(int u, int p)
    {
        table[0][u] = p;
        for (int v : tree[u])
        {
            if (v == p)
                continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
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
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n  ,  q;
    cin>>n;
    vvi  tree( n + 1 ) ;
    f( i , 0 , n-1 )
    {
        int u ,  v  ; 
        cin>>u>>v ; 
        tree[u].push_back(v) ; 
        tree[v].push_back(u) ;
    }
    cin>>q ;
    LCA L( tree );
    while( q-- > 0 )
    {
        int k ;
        cin>>k ;
        bool ans = true  ;
        vi v( k , 0 ) ; 
        f( i , 0 ,  k ) cin>>v[i] ; 
        mii m ; 
        f( i , 0 , n )m[v[i]]++ ; 
        f( i , 0 , k-1 )
        {
            int a  = L.lca( v[i] , v[i+1]) ; 
            if( m[a] == 0  )
            {
                 ans = false  ;
                 break ;
            }
        }
        if( ans )cout<<"YES"<< endl ;
        else cout<<"NO"<<endl ;
    }
    return 0;
}