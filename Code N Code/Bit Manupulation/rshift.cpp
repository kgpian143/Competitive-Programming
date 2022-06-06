#include<bits\stdc++.h>
using namespace std ;

int main()
{
    int t ;
    cin>>t ;
    while( t-- > 0 )
    {
        int n , p ;
        cin>>n>>p ;
        cout<<n<<" >> "<<p <<" : "<<(n >> p )<<endl;
    }
}