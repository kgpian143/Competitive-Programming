#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
const int N = 1e5 + 10 ;
vector<int> divisors[N] ;
int main()
{
    int t ;
    cin>>t ;
    for( int i = 2  ; i < N ; i++ )
    {
        for( int j = i ; j < N ; j+= i )
        {
            divisors[j].push_back(i) ;
        }
    }
    for( int i = 2 ; i <  24 ; i++ )
    {
        cout<< i << " : ";
        for( auto it : divisors[i])
        {
            cout<<it<<" " ;
        }
        cout<<endl ;
    }
    return 0 ;
}