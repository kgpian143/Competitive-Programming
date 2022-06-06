#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
const int N = 1e7 + 10 ;
vector<bool> isPrime( N ,  1) ;
vector<int> high_prime( N ,  0) ;
vector<int> low_prime( N ,  0) ;
int main()
{
    isPrime[0] =  isPrime[1] = false ;
    low_prime[1] = high_prime[1] = 1 ;
    for( int i = 2 ; i < N ; i++ )
    {
        if(isPrime[i] == true )
        {
            low_prime[i] = high_prime[i] = i ;
            for( int j = 2*i ; j < N ; j+= i)
            {
                isPrime[j] = false ;
                high_prime[j] = i ;
                if( low_prime[j] == 0 )low_prime[j] = i ;
            }
        }
    }
    // for( int  i = 1 ; i <= 100 ; i++)cout<<i<< " lowest Prime : "<<low_prime[i]<<"  , highest Prime : "<<high_prime[i]<<endl ;
    // return 0;
    int t;
    cin>>t ;
    while( t-- > 0 )
    {
        int n ;
        cin>>n ;
        unordered_map <int , int > prime_factors ;
        while( n > 1 )
        {
            prime_factors[low_prime[n]]++ ;
            n = n / low_prime[n] ;
        }
        for( auto it : prime_factors )
        {
            cout<<it.first<<"^"<<it.second<<"  " ;
        }
        cout<<endl ;
    }
}