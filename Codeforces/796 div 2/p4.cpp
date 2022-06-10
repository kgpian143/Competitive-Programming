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
const int N = 2e5 + 5 ; 
int pref[N] ;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n , k , ans = 0 ;
        cin>>n>>k;
        vi  v(n , 0 ) ;
        f(i,0,n)cin>>v[i] ;
        if( k >= n )
        {
            ans = accumulate(all(v) ,  ans) ;
            ans += k*n ;
            ans =  ans  - ((n*(n+1))/2) ;
        }
        else 
        {
            int max_sum = 0 ;
            for( int i = 1 ; i <= n ; i++ )pref[i] = pref[i-1] + v[i-1] ;
            for( int i = 0 ; i <= n - k  ; i++ )max_sum = max( max_sum , pref[i + k ] - pref[i]);
            ans = max_sum ;
            ans += (k * (k-1))/2 ;
        }
        cout<<ans<<endl;
    }
    return 0;
}