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

int binaryexp_( int n , int k )
{
    int ans = 1 ;
    while( k > 0 )
    {
        if( k & 1 )
        {
            ans = (ans*1LL*n)%mod ;
        }
        n = (n*1LL*n)%mod ;
        k >>= 1 ;
    }
    return ans;
}

bool check( int k , int a , int b )
{
    while( k > 0 )
    {
        int d = k%10 ;
        if( d != a && d != b )return false ;
        k = k/10 ;
    }
    return true ;
}

bool good( int a , int b , int n ,  int k , int num )
{
    if( ( a*k + b*(n-k)) <= num  )return true ;
    else return false ; 
}
void solve()
{
    int a , b , n ;
    cin >> a >>  b >> n ;

    if( a < b )swap( a , b ) ;

    vi num ;
    vi fact( n + 1 , 1 ) ;
    int ans = 0 ; 
    for( int i = 2 ; i <= n ; i++ )
    {
       fact[i] = (fact[i-1]*i)%mod ;
    }
    for( int i = 0 ; i <= 9 * n ; i++  )
    {
        if( check( i , a , b ))num.push_back(i) ;
    }

    for( auto it : num )
    {
        int l = 0 , h = n + 1 ;
        while( h - l > 1 )
        {
            int m = (l+h) >> 1 ;
            if( good( a , b , n , m , it ))l = m ;
            else h = m ;
        }

        if((a*l + b * ( n - l)) == it )
        {
            int res = fact[n];
            int den = (fact[n-l]*1LL*fact[l])%mod ;
            res = (res  * binaryexp_(den , mod - 2 ) ) % mod ;
            ans = ( ans + res) % mod ;
        }
    }
    cout << ans << "\n" ;
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