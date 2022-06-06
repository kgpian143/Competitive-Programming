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
int w , h , n ;
const int N = 2e5 + 5  ;
int table[N] ;
bool func( int x )
{
    return ( (x / w)* (x/h) >= n) ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    cin>>w>>h>>n ;
    int l = 0 ;
    int r = 1;
    while( !func(r)) r *= 2 ;
    while( r - l > 1  )
    {
        int mid = ( l + r )>>1 ;
        if(func(mid))r = mid ;
        else l = mid  ;
    } 
    cout<<r ;
    return 0;
}