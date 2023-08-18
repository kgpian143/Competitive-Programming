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



struct range{
    int a ;
    int b ;
    int l ;
    int r ;
};

bool comp( const range &a , const range &b )
{
   return a.l < b.l ; 
}
void solve()
{
    int n ;
    cin >> n ;
    vector<range> v(n) ;
    for( int i = 0 ; i < n ; i++ )
    {
        cin >> v[i].l >> v[i].r >> v[i].a >> v[i].b ; 
    }
    sort( v.begin() , v.end() , comp ) ; 
    vi a ;
    a.push_back(v[0].l) ; 
    int j = 0 ;
    for( int i = 1 ; i < n ; i++ )
    {
       if( v[i].l > v[j].b)
       {
          a.push_back(v[j].b) ; 
          a.push_back(v[i].l) ;
          j = i ;
       }
       else if( v[j].b <= v[i].b ) j = i ;
    }
    a.push_back(v[j].b) ;

    int q ;
    cin >> q ;
    while( q-- > 0 )
    {
        int x ;
        cin >> x ;
        int ind = upper_bound( all(a) , x ) - a.begin() ;
        if( ind & 1 )
        {
            cout << a[ind] << " " ;
        }
        else cout << x << " " ;
    }
    cout << endl ;  
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