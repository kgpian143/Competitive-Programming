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
const int N = 2e5 + 5; 
int ind[N] ;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n ;
    cin>>n ;
    vi v(n , 0 ) ;
    f(i,0,n)
    {
        cin>>v[i] ;
        // ind[v[i]] = i ;
    }
    int cnt = 0 ;
    mii m ;
    for( int i = 0 , j = 0  ; i < n ;i++)
    {
        j = max( m[v[i]] , j ) ;
        cnt = max( cnt  , i - j + 1 );
        m[v[i]] = i + 1  ;
    }
    cout<<cnt<<endl;
    return 0;
}