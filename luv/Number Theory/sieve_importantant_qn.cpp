#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
const int N = 1e5 + 10 ;
// vector<bool> isPrime( N ,  1) ;
vector<int> high_prime( N ,  0) ;
// vector<int> low_prime( N ,  0) ;
int main()
{
    // isPrime[0] =  isPrime[1] = false ;
    for( int j = 2 ; j < N ; j++ )
    {
        if( high_prime[j] == 0 )
        {
            for( int i = j ; i < N ; i += j )high_prime[i] = j ;
        }
    }
     
    // for( int  i = 1 ; i <= 100 ; i++)cout<<i<< " lowest Prime : "<<low_prime[i]<<"  , highest Prime : "<<high_prime[i]<<endl ;
    // return 0;
    int k , t;
    cin>> k >> t ;
    vector<int> hsh( N , 0 ) ;
    hsh[1] = 1 ;
    for( int i = 0 ; i < k ; i++)
    {
        int a ; 
        cin>>a ;
        if( a == 1 )continue ;
        for( long long int j =  a ; j < N ; j= j*a )hsh[j] = 1 ;
    }
    while( t-- > 0 )
    {
        // cout<<"a\n";
        int x ;
        cin>>x ;
        vector <int > prime_factors ;
        int n = x ;
        while( n > 1 )
        {
            int k = high_prime[n] ;
            while( n % k == 0 ) n = n / k ;
            prime_factors.push_back(k) ;
        }
        bool ispossible = false ;
        for( int i = 0 ; i < prime_factors.size() ; i++ )
        {
            for( int j = i ; j < prime_factors.size() ; j++ )
            {
                int prod = prime_factors[i] * prime_factors[j] ;
                if( i == j && (x % prod) != 0  )continue ;
                if( hsh[x/prod] == 1 )
                {
                    ispossible = true ;
                    break ;
                }
            }
            if( ispossible)break ;
        }
        cout<<( ispossible ? "YES\n" : "NO\n") ;
        // cout<<endl ;
    }
}