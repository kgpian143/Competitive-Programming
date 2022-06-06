#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
int main()
{
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n ; 
        cin>> n;
        vector<int>  factors( sqrt(n) + 1 , 0 ) ;
        for( int i = 1 ;  i*i <= n ; i++ )
        {
            if( n % i == 0  )
            {
                cout<<i<<" "<<n/i<<endl ;
                if( n / i != i )
                {
                    factors.push_back(i) ;
                    factors.push_back(n/i) ;
                }
                else factors.push_back(i) ;
            }
        } 
    }
    return 0;
}