#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int t ;
    cin>>t ;
    while( t-- > 0 )
    {
        int a , b ;
        cin >> a >> b ;
        if( 10*a > 5*b )
        {
            cout<<"FIRST"<<endl ;
        }
        else if( 10*a < 5*b )
        {
            cout<<"SECOND"<<endl ;
        }
        else cout<<"ANY"<<endl ;
    }
    return 0;
}