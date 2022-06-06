#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int t ;
    cin>>t ;
    while( t-- > 0 )
    {
        int n , k ;
        cin>>n>>k ;
        int p = (n)/(__gcd(n,k)) ;
        cout<<p<<endl ;
    }
    return 0;
}