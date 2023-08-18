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

void dfs( int v , int p , vi tree[] , vi &indp , map< pii , int > &m)
{
    for( auto it : tree[v])
    {
        if( it == p )continue;
        if( m[ { it , v} ] > m[ { v , p }] )indp[it] = indp[v] ;
        else indp[it] = indp[v] + 1 ;
        dfs( it , v , tree , indp , m ) ;
    }
}

void solve()
{
    int n ;
    cin >> n ;
    vi tree[ n+ 1] ;
    map< pii , int > m ;
    for( int i = 0 ; i < n - 1 ; i++ )
    {
        int u , v ;
        cin >> u >> v ;
        tree[u].push_back(v) ;
        tree[v].push_back(u) ;
        m[{ u , v}] = i + 1 ;
        m[{ v , u}] = i + 1 ;
    }

    vi indp( n + 1 , 0 ) ;
    indp[1] = 1 ;
    m[{0,1}] = 0 ;
    m[{1,0}] = 0 ;
    dfs( 1 , 0 , tree , indp , m ) ;
    int ans = *max_element( all(indp)) ;
    cout << ans <<'\n' ;
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