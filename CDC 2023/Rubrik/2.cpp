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

int binaryexp_iterative( int n , int k )
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

void solve()
{
    int n , a , b ; 
    cin >> n >> a >> b ;
    vector<int> v(n , 0 ) ;
    multiset<int> s;
    for( int i = 0 ; i < n ; i++ )
    {
        cin >> v[i] ; 
        s.insert(v[i]) ;
    }

    for( int i = 0 ; i < b ; i++ )
    {
        auto st = s.begin() ; 
        auto end = s.end() ;
        end-- ; 
        if( ( *end / *st )  <= a )
        {
            b = b - i ;
            break ;
        }
        s.erase(st) ; 
        s.insert((*st ) * a ) ;
    }

    int q = b / n ; 
    int r = b % n ; 

    int k = binaryexp_iterative( a , q ) ; 
    
    int ind = 0 ;
    multiset<int> ans ;
    for( auto it : s ){
        if( ind < r )
        {
            ans.insert( ((( it * a ) % mod) * k ) % mod ) ;
        }
        else {
            ans.insert(( it * k ) % mod) ;
        }
        ind++ ;
    }
    for( auto it : ans )cout << it << endl;
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