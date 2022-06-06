#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define int long long 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef pair<int, int> pii;  
typedef pair<int, bool> pib;  
typedef unsigned long long ull; 
typedef long double ld; 
typedef vector<pii> vpii; 
const int N = 1e5 ;
int n , k ;
vi v(N , 0 ) ;
bool good( double x )
{
    double ans = 0 ;
    for( int i = 0 ; i < n ; i++)
    {
         ans += floor( v[i] / x) ;
    }
    return ans >= k ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    cout<<setprecision(20) ;
    cin>>n>>k;
    f(i,0,n)cin>>v[i] ;
    double l = 0 ;
    double r = 1e8 ;
    for( int i = 0 ; i < 100 ; i++ )
    {
        double mid = ( l + r )/2 ;
        if( good(mid) ) l = mid  ;
        else r = mid  ;
        // cout<<setprecision(20)<<l<<" "<<r<<endl ;
    }
    cout<<l<<endl ;
    return 0;
}