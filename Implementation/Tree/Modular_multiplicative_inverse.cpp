#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
// ( A * B ) % mod  = 1 B called modular multiplicative inverse of A 
// It  exist only if mod is A and mod is coprime so 1 <=  B  <= mod -1 
//************* Fermat Theoram ***************
// (A ^ mod-1 )% mod  = 1  mod is a prime number 
// ( (A ^ m-2) % mod ) = A ^ (-1) 
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
int mmi( int n )
{
    return binaryexp_( n , mod - 2 ) ;
}
int main()
{
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n ;
        cin>>n ;
        cout<<mmi(n) ;
    }
    return 0;
}