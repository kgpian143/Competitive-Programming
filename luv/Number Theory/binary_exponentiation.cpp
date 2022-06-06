#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007
const long long int M = 1e18 + 7 ;

int binaryexp_recursive( int n , int k )
{
    if( k == 0 )return 1 ;
    if( k&1 )
    {
        int a = binaryexp_recursive(n , k/2 );
        return (n*((a*1LL*a)%mod))%mod ;
    }
    else 
    {
        int a = binaryexp_recursive(n , k/2 );
        return (a*1LL*a)%mod ;
    }
}
int binaryexp_iterative( int n , int k )
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
int binaryexp1( long long int n , int k ) // n <= 10^18 
{
    n = n % mod ; // take mode of n 
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
long long binarymultiply( long long int a  ,  long long int b )
{
    long long int ans = 1 ;
    while( b > 0 )
    {
        if( b & 1 )
        {
            ans = (ans + a)%M ;
        }
        a = (a+a)%M ;
        b >>= 1 ;
    }
    return ans;
}
long long int binaryexp2( long long int n , int k ) // n <= 10^18  , mod <= 10^18 we can't multiply 10^18 to 10^18 this go for overflow we use multiplication of large number 
{
    n = n % mod ; // take mode of n 
    int ans = 1 ;
    while( k > 0 )
    {
        if( k & 1 )
        {
            ans = (binarymultiply( ans , n))%M ;
        }
        n = (binarymultiply(n , n))%M ;
        k >>= 1 ;
    }
    return ans;
}
// if b <= 10^18 this programme is correct for all values of b but in (a^b)^c % mod is not valid 
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
//  (a^b)^c
// ****** ETF Value ******** 
// for number n -> counts of k such that 1<= k <= n  ( k , n ) are coprime 
//for a prime number counts will be n-1
// ETF value = n * ( 1 - 1/p1)*( 1- 1/p2 )* ....... ( 1 - 1/pk) where  p1 , p2 , .... , pk  are prime factors 
// Using ETF value function 
// (a ^ b) % mod = ( a ^ ( b % phi(n))) %phi(n)  phi(n) is ETF value of n    
int main()
{
    long long int a = 17165461631653 , b = 264613116 ;
    cout<<binaryexp_recursive(a,b)<<endl ;
    cout<<binaryexp_iterative(a,b)<<endl ;
    return 0;
}