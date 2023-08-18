#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<long long, null_type, less<long long>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set; // *find_by_order,
// order_of_key

#define ll long long
#define ft first
#define sd second
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define pll pair<long long, long long>
#define vp vector<pair<long long, long long>>
#define fr(i,b,e) for(ll i=b; i<e; i++)
#define inpt(a,n) for(ll i=0; i<n; i++) cin>>a[i];
#define all(v) v.begin() , v.end()
#define en '\n'
const ll M=1000000007;

ll n,m;
vector<vector<ll>> g;
vector<pair<ll,ll>> edges;
vector<ll> visited;
ll dp[105][2];

void dfs(ll nn, ll cmp)
{
    visited[nn] = cmp;
    for(auto ch: g[nn])
    {
        if(!visited[ch])
        {
            dfs(ch, 3-cmp);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen('input.txt', 'r', stdin); // change to double quotes
// when uncomment
//     //freopen('output.txt', 'w', stdout); // change to double quotes
// when uncomment

    cin>>n>>m;
    g.resize(n+1);
    visited.assign(n+1,0);
    ll nodes[101]={0};
    fr(i,0,m)
    {
        ll x,y;
        cin>>x>>y;
        nodes[x]=1;
        nodes[y]=1;
        edges.pb({x,y});
        g[x].pb(y);
        g[y].pb(x);
    }

    for(ll i=1; i<=n; i++)
    {
        if(!visited[i])
            dfs(i,1);
    }

    ll ans=0;
    for(auto it: edges)
    {
        if(visited[it.first]==visited[it.second])
        {
            ans++;
        }
    }


    cout<<ans;

    return 0;
}