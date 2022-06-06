#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int t ;
    cin>>t ;
    while( t-- > 0 )
    {
        int n ;
        cin>>n ;
        int k = log2(n) ;
        cout<<max((n-pow(2,k)+1), pow(2,k-1))<<endl;
    }
    return 0;
}