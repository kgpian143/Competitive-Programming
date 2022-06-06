#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
bool hasGroupsSizeX(vector<int>& deck) {
    map<int , int > m ;
    // bool ispossible ;
        for( int i = 0 ; i < deck.size() ; i++ )
        {
            m[deck[i]]++ ;
        }
        int min_cnt = INT_MAX ;
        for( auto it : m )
        {
            min_cnt = min( min_cnt , it.second) ;
        }
        if( min_cnt == 1 )return false ;
        for( auto it : m )
        {
            min_cnt = __gcd( min_cnt ,  it.second ) ;
        }
        return (min_cnt > 1) ;
    }
int main()
{
    int t ;
    cin>>t ;
    while( t -- > 0 )
    {
        int n ;
        cin>>n ;
        vector<int> v ( n , 0 ) ;
        for( int i = 0 ; i < n ; i++)cin>>v[i] ;
        cout<<hasGroupsSizeX(v)<<endl ;
    }
    return 0;
}