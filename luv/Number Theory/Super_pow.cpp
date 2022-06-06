#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
int binaryexp_( int n , int k , int m  )
{
    int ans = 1 ;
    while( k > 0 )
    {
        if( k & 1 )
        {
            ans = (ans*1LL*n)%m ;
        }
        n = (n*1LL*n)%m ;
        k >>= 1 ;
    }
    return ans;
}
int main()
{
    int a , b , c ;
    cin>>a>>b>>c ;
    cout<<binaryexp_( a , binaryexp_( b ,  c , mod-1 ) , mod) <<endl; 
    return 0;
}