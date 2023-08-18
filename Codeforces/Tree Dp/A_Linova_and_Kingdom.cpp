#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define int  long long  
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<int> vl;
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii;
typedef map<int, int> mll;
typedef pair<int, int> pii;  
typedef pair<int, bool> pib; 
typedef pair<int, int> pll; 
typedef unsigned int ull; 
typedef long double ld; 
typedef int ll; 
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;
const int N = 1e5 + 5 ;

void dfs(int cur,int par,vi& cnt,vvi& tree, vi& dep)
{
    cnt[cur] = 1;
    for(auto& ele : tree[cur])
    {
        if(ele == par) continue;
        dep[ele] = 1+dep[cur];
        dfs(ele,cur,cnt,tree,dep);
        cnt[cur] += cnt[ele];
    }
}

void solve()
{
    int n , k ;
    cin >> n >> k ;
    vvi tree(n) ;
    for( int i = 1 ; i < n ; i++)
    {
        int u , v ;
        cin >> u >> v ;
        tree[--u].push_back(--v);
        tree[v].push_back(u);
    }
    vector<int> cnt(n),dep(n);
    dfs(0,0,cnt,tree,dep);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<i+1<<" --> "<<cnt[i]-1<<" : "<<dep[i]<<endl;
    // }
    set<pair<int,int>> que;
    for(int i=0;i<n;i++)
    {
        que.insert(make_pair(dep[i]-cnt[i]+1,i));
    }
    int ans = 0;
    while(k--)
    {
        int cur = que.rbegin()->first;
        // cout<<que.rbegin()->second + 1<<" : "<<que.rbegin()->first<<"\n";
        que.erase(--que.end());
        ans += cur;
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t = 1; 
    // cin>>t ; 
    while(t-- > 0 )
    {
        solve() ;
    }
    return 0;
}