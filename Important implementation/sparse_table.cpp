#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
const int max_n = 1e5;
int table[max_n][25] ; 
void make_table( vector<int> v )
{
    int n = v.size() ;
    for( int l = n -1 ; l >= 0 ; l-- )
    {
        for( int w = 0 ; w < 25 ; w++ )
        {
            int r = l + ( 1 << w ) - 1 ;
            if( r >= n )break ;
            if( w == 0 )table[l][w] = v[l] ;
            else table[l][w] = min( table[l][w-1] , table[l +  ( 1 << (w-1))][w-1]) ; 
        }
    }
}

int main()
{
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
    
    }
    return 0;
}