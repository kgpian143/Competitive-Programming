#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
const int N = 1e7 + 10 ;
vector<bool> isPrime( N ,  1) ;
int main()
{
    int t ;
    cin>>t ;
    isPrime[0] =  isPrime[1] = false ;
    for( int i = 2 ; i < N ; i++ )
    {
        if(isPrime[i] == true )
        {
            for( int j = 2*i ; j < N ; j+= i)isPrime[j] = false ;
        }
    }
    while(t-- > 0 )
    {
       int n ;
       cin>>n ; 
       if( isPrime[n] )
       {
           cout<<"Prime\n";
       }
        else cout<<"Not Prime\n";
    }

    return 0;
}