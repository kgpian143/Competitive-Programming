#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl; 
typedef vector<vector<bool>> vvb ;
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
const int N = 1005 ;
char g[N][N] ;
bool vis[N][N] ;
int n , m ;
void dfs( int i , int j )
{
    if( g[i][j] == '#')return ;
    if( vis[i][j] == true)return ;
    if( i < 1 || j < 1 )return;
    if( i > n || j > m )return;
    vis[i][j] = true ;
    dfs(i-1 , j );
    dfs(i , j+1 );
    dfs(i+1 , j );
    dfs(i , j-1 );
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    cin>>n >> m ;
    for( int i = 1 ; i <= n ; i++)
    {
        for( int j = 1 ; j <= m ; j++)
        {
            cin>>g[i][j] ;
        }
    }
    int cnt = 0 ;
    for( int i = 1 ; i <= n ; i++)
    {
        for( int j = 1 ; j <= m ; j++)
        {
            if( g[i][j] == '#')continue ;
            if( vis[i][j] )continue;
            dfs(i,j) ;
            cnt++ ;
        }
    }
    cout<<cnt<<endl;
    return 0;
}