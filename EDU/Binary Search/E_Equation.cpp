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
double c ;
bool good( double x ){
    return x*x + sqrt(x) >= c ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t = 1 ;
    // cin>>t ;
    while(t-- > 0 )
    {
        cin>>c ;
        double l = 0 ;
        double r = c ;
        cout<<setprecision(20) ;
        for( int i = 0  ; i < 100 ; i++ )
        {
             double m = ( l + r )/2 ;
             if(good(m))r = m ;
             else l = m ;
            //  cout<<l<<" "<<r<<endl;
        }
        cout<<r;
    }
    return 0;
}