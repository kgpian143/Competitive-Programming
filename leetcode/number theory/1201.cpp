#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007
 int nthUglyNumber(int n, int a, int b, int c) {
        // binary_search
        int l = 1 ; 
        int h = 2e9 ;
        int ab = a*b/(__gcd(a , b)) ;
        long long int bc = c*1LL*b/(__gcd(c , b)) ;
        long long int ac = c*1LL*a/(__gcd(c , a)) ;
        long long int abc = ab *1LL* c / (__gcd(ab ,  c)) ;
        while( l < h )
        {
            int mid =  l + ( h - l )/2;
            int k = mid/a + mid/b + mid/c - mid/ab - mid / bc - mid / ac + mid/abc  ;
            if( k >= n )h = mid ;
            else l = mid + 1 ;
        }
        return l;
        // lcm
    } 
int main()
{
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
         int n , a , b , c ;
         cin>>n>>a>>b>>c ;
         cout<<nthUglyNumber(n,a,b,c)<<endl; 
    }
    return 0;
}