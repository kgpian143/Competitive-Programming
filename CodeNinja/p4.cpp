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
int colorfulGraph(int n, int m, vector<vector<int>> &edges, int k, vector<int> &c) {
    // Write your code here.
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ; 
    cin>>t ; 
    while(t-- > 0 )
    {
        int n ,  m; 
        cin >> n , m ; 
        vector<vi> edges(n) ;
        vi v(n) ;
        f( i , 0 , n )cin >> v[i] ;
        f( i , 0 , m )
        {
            int a , b ;
            cin >> a >> b ;
            edges[i].push_back(a);
            edges[i].push_back(b);
        }
        
    }
    return 0;
}