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
int main()
{
    // a ^ 0 -> a 
    // a ^ a ->  0
    // x ^ y ^ z == x^ z ^ y associative property ;
    // swapping the numbers
    int a = 4 ,  b = 6 ;
    cout<<" a - > "<<a << " b  -> "<<b <<endl ;
    a = a ^ b ;
    b = b ^ a ;
    a = a ^ b ; 
    cout<<"After swap a -> "<<a<<" b -> "<<b <<endl ;
    
}