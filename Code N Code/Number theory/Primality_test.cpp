#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 

bool isprime( int n ) 
{
    if( n == 2 )return false ;
    for( int i = 2 ; i <= sqrt(n) ; i++ )
    {
        if( n % i == 0 )return false ;
    }
    return true ;
}
int main()
{
    int n ;
    cin>>n ;
    (isprime(n)) ? cout << "YES" : cout << "NO" ;
    return 0;
}