#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007
const int N = 500 + 5;
int inf = 1e12 + 10;

int dist[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = inf;
        }
    }
    int n, m , q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        dist[x][y] = min(dist[x][y] , wt);
        dist[y][x] = min( dist[x][y] , wt) ;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while( q-- > 0 )
    {
        int i , j ;
        cin>>i>>j ;
        if( dist[i][j] == inf )cout<<-1<<endl;
        else cout<<dist[i][j]<<endl ;
    }
    return 0;
}