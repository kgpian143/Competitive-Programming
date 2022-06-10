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
int m , n ;
vi t , z , y ; 
bool good( int x )
{
    int ans = 0 ;
    for( int i = 0 ; i < n ; i++)
    {
        int k = x / ( z[i] * t[i] + y[i]) ;
        int r = x % ( z[i] * t[i] + y[i]) ;
        ans += k*z[i] + min(r , z[i] * t[i])/ t[i]  ;
    }
    return ans >= m ;
} 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    cin>>m>>n;
    t.resize(n) ;
    z.resize(n) ;
    y.resize(n) ;
    f(i,0,n)
    {
        cin>>t[i]>>z[i]>>y[i] ;
    }
    int l = -1 ;
    int h =  1e12 + 1 ;
    while( h - l  > 1 )
    {
        int m = ( l + h )/2 ;
        if(good(m))h = m ;
        else l = m ;
        // cout<< l << " "<< h <<endl ;
    }
    cout<<h << endl;
    vi  ans ;
    int cnt = 0 ;
    for( int i = 0 ; i < n ; i++)
    {
        int k = h / ( z[i] * t[i] + y[i]) ;
        int r = h % ( z[i] * t[i] + y[i]) ;
        cnt +=  k*z[i] + min(r , z[i] * t[i])/ t[i] ;
        ans.push_back( k*z[i] + (min(r , z[i] * t[i]))/ t[i]) ;
    }
    // sort(all(ans)) ;
    cnt -= m ;
    for( auto it : ans )
    {
        if( cnt > 0) 
        {
            cout<<it-1<<" ";
            cnt-- ;
        }
        else cout<<it<<" ";
    }
    return 0;
}