#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
const int N = 1e6 + 7 ;
int fact[N] ;
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

int main()
{
    int t ;
    cin>>t ;
    fact[0]= fact[1] = 1  ;
    for( int i = 2 ; i < N ; i++ )
    {
       fact[i] = (fact[i-1]*1LL*i)%mod ;
    }
    while(t-- > 0 )
    {
        int n , r ;
        cin>>n>>r ;
        int ans = fact[n];
        int den = (fact[n-r]*1LL*fact[r])%mod ;
        ans = (ans * 1LL * binaryexp_(den , mod - 2 ) ) % mod ;  
        cout<<n<<" C "<<r<<" : "<<ans<<endl ;
    }
    return 0;
}