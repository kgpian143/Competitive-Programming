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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n ;
        cin>>n ;
        if( n == 1 )cout<<3<<endl;
        else if( (n & 1) == 1 )cout<<1<<endl;
        else 
        {
            int k = 0 ;
            while( (n & 1) == 0 )
            {
                n = n>>1 ;
                k++ ;
            }
            if( n == 1 )cout<<(( 1 << k ) + 1)<<endl ;
            else cout<<(1<<k)<<endl;
        }
    }
    return 0;
}