#include<bits/stdc++.h>
using namespace std ;

void printbinary( int n )
{
    for( int i = 10 ; i >= 0 ; i-- )
    {
        cout<<((n>>i)& 1 );
    }
    cout<<endl ;
}
bool isbitset( int n , int k )
{
    if(( n & ( 1 << k )) != 0 )return true ;
    else return false ;
}
int setbit( int n , int k )
{
    n = n | (1<<k) ;
    return n ;
}
int unsetbit( int n , int k )
{
    n = n & ( ~( 1 << k )) ;
    return n ;
}
int toggle( int n , int k )
{
    n = n ^ ( 1 << k ) ;
    return n ; 
}
int main()
{
    int n , k;
    cin>> n >> k ;
    printbinary(n);
    (isbitset(n,k)) ? cout<<"Bit set"<<endl : cout<<"Bit not set "<<endl ;
    printbinary(setbit( n , 6 )) ;
    printbinary(unsetbit( n , 0 ) );
    printbinary(toggle(n,5));
}