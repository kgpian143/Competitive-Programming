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
    for( char c = 'A' ; c <= 'E' ; c++ )
    {
        cout<< c << endl;
        printbinary(c) ; 
    }
    // only 5th bit differ in binary representation
    for( char c = 'a' ; c <= 'e' ; c++ )
    {
        cout<< c << endl;
        printbinary(c) ; 
    }
    char a = 'a' ;
    cout<< char( a & '_')<<endl ; // converting the lowercase to uppercase
    char A = 'A' ;
    cout<< char( A | ' ')<<endl ;// converting uppercase to lowercase
}