#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 

void solve( int a  , int n ) 
{
    int res  = 1 ;
    while( n > 0 )
    {
        if( n%2 == 1 )
        {
            res *= a ;
            n-- ;
        }
        else 
        {
            n /= 2 ;
            a *= a ;
        }
    }
    // res = a*res ;
    cout<<res ;
}
int main()
{
    int a , n ;
    cin>> a >> n ;
    solve(a , n);
    return 0;
}