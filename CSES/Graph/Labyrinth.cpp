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
int n, m;
const int N = 1005;
char g[N][N];
bool vis[N][N];
char path[N][N];
pii parent[N][N];
// string path;
bool isvalid(int i, int j)
{
    if (vis[i][j])
        return false;
    if (i < 1 || j < 1)
        return false;
    if (i > n || j > m)
        return false;
    if (g[i][j] == '#')
        return false;
    return true;
}
bool bfs(pii src)
{
    queue<pii> q;
    bool ispossible = false;
    vis[src.first][src.second] = true ;
    q.push(src);
    while (!(q.empty()))
    {
        pii a = q.front();
        q.pop();
        int i = a.first;
        int j = a.second;
        if (g[i][j] == 'B')
        {
            ispossible = true;
            break;
        }
        else
        {
            if (isvalid(i + 1, j))
            {
                path[i + 1][j] = 'D';
                parent[i + 1][j] = {i, j};
                vis[i+1][j] = true ;
                q.push({i + 1, j});
            }
            if (isvalid(i-1, j))
            {
                path[i - 1][j] = 'U';
                vis[i-1][j] = true ;
                q.push({i - 1, j});
                parent[i - 1][j] = {i, j};
            }
            if (isvalid(i, j + 1))
            {
                path[i][j + 1] = 'R';
                vis[i][j+1] = true ;
                q.push({i, j + 1});
                parent[i][j + 1] = {i, j};
            }
            if (isvalid(i, j - 1))
            {
                path[i][j - 1] = 'L';
                vis[i][j-1] = true ;
                q.push({i, j - 1});
                parent[i][j - 1] = {i, j};
            }
        }
        
    }
    return ispossible ;
}

void printpath( pii st ,  pii dest)
{
    string s ;
    int i = dest.first ;
    int j = dest.second ;

    while( make_pair(i , j) != st )
    {
        // cout<<st.first<<st.second<<" ";
        // cout<<i<<j<<" ";
        s.push_back(path[i][j]) ;
        int t1 = i ;
        int t2 = j ;
        i = parent[t1][t2].first ;
        j = parent[t1][t2].second ;
    }
    reverse(all(s)) ;
    cout<<s.size() <<endl;
    cout<<s ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    pii st, dest;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'A')
            {
                st.first = i;
                st.second = j;
            }
            if (g[i][j] == 'B')
            {
                dest.first = i;
                dest.second = j;
            }
        }
    }
    if( bfs(st))
    {
        cout<<"YES"<<endl;
        printpath(st ,  dest);
    }
    else cout<<"NO";
    return 0;
}