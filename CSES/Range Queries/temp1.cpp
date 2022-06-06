#include<iostream>
using namespace std;

int main()
{
    int t ;
    cin>>t ;
    while( t-- > 0 )
    {
        int n , temp ;
        cin>>n ;
        int sum = 0 ;
        temp = n ;
        while( n > 0 )
        {
            int r ;
            sum = 10*sum ;
            r = n % 10 ;
            sum = sum + r ;
            n = n/10 ;
        }
        if( temp == sum  )cout<<"wins\n";
        else cout<<"loses\n";
    }
}