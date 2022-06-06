#include<bits/stdc++.h>
using namespace std ;
// void solve( int )
int main()
{
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int x ;
        cin >> x ;
        if( x >= 1000 )
        {
            int a = x/10 ;
            cout<<a<<endl ;
        }
        else cout<<100<<endl;
    }
    return 0;
}