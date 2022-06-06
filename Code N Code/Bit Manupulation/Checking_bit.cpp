#include<bits\stdc++.h>
using namespace std ;

int main()
{
    int t ;
    cin>>t ;
    while( t-- > 0 )
    {
        int n , k;
        cin>>n>>k;
        ( (n  & (1 << k))) ? cout<<"YES\n" : cout<<"NO\n"  ;
    }
}