#include<bits/stdc++.h>
using namespace std ;

int sametrait( string str1 , string str2 )
{
    for( int i = 0 ; str1[i] != '\0' ; i++)
    {
        if(str1[i] == str2[i])return 1 ;
    }
    return 0 ; 
}
int main()
{
    int t ;
    cin >> t ;
    while( t-- > 0)
    {
        long long int n , m ;
        cin >> n >> m ;
        vector<string> str(n) ;
        for( int i = 0 ; i < n ; i++ )
        {
            cin >> str[i] ;
        }
        long long int k ;
        k = pow( 2 , n ) - 1 ;
        for( int i = 0 ; i < n-1 ; i++)
        {
            if( sametrait(str[i] , str[i+1]))
            {
                k = k - pow(2,n-2) ; 
            }
        }
        k = k % int(( pow(10,9) + 7)) ;
        cout << k ;
    }
    return 0;
}