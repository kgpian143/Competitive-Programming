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

int solve( int n , int m , int x , int p , int u , int q, int v)
{
    int a = abs( p-q ) ;
    int b = abs( u - v) ;
    
    float r = sqrt( x - 1 ) ;
    if( r - (int)r * (1.0) > 0 )
    {
        if(( a % x == 0 ) && ( b % x == 0 ))return a / x + b / x ;
        else return -1 ;
    }
    else 
    {
        int k = x - 2 ;
        int t = r * 2 ;
        
        if( a % k == 0 )
        {
            int b1 = b + t * a / k ;
            if( b1 >=  m  )
        }

    }
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