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
typedef vector<vector<int>> vvl; 
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

void solve()
{
    char grid[8][8] ;
    int ind = -1 ;
    string ans ;
    for( int i = 0 ; i < 8 ; i++)
    {
        for( int j = 0; j < 8 ; j++)
        {
            cin >> grid[i][j];
            if( grid[i][j] != '.')
            {
                ans.push_back(grid[i][j]);
            }
        }
    }
    cout << ans << "\n" ; 
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ; 
    cin>>t ; 
    while(t-- > 0 )
    {
        solve() ;
    }
    return 0;
}