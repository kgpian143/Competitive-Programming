#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
typedef vector<int> vi; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef map<long long, long long> mll;
typedef pair<int, int> pii;  
typedef pair<long long, long long> pll; 
typedef unsigned long long ull; 
typedef long double ld; 
typedef long long ll; 
typedef vector<vector<int>> vvi; 
typedef vector<pii> vpii; 
int divide( int n , int d )
{
    // cout<<n;
    if( n == INT_MIN && d == -1)return INT_MAX ;
    if( d == 1)return n ;
    // cout<<1;
    int sign = ( n > 0 )^( d > 0 ) ? -1 : 1 ;
    int q  = 0 ;
    // cout<<1;
    long long n1 = llabs(n) ;
    long d1 = labs(d) ;
    // cout<<n1;
    while( n1 >= d1)
    {
        // cout<<1;
        long long temp = d1 ;
        int k = 1 ;
        while( temp << 1 <= n1 )
        {
            temp = temp << 1 ;
            k = k << 1;
        }
        n1 -= temp ;
        q += k ;
    }
    return q*sign ;
}
int main()
{
    int t ;
    cin>>t ;
    while( t-- > 0)
    {
        int n , d ;
        cin>>n>>d ;
        cout<<divide(n,d)<<endl ;
    }
    return 0;
}