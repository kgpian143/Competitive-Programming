#include<bits/stdc++.h>
using namespace std ;
int lb( vector<int> v , int a , int  n )
{
    int l = -1 ;
    int h = 
}
int ub( vector<int> v , int a , int n )
{

}
int main()
{
    int n ;
    cin>>n ;
    vector<int> v ;
    for( int i = 0 ; i < n ; i++)
    {
        int a ;
        cin>>v[i] ;
    }
    int k ;
    cin>>k ;
    while(k-- > 0 )
    {
        int a ;
        cin>>a  ;
        cout<<lb( v , a , n )<< " "<<ub( v , a , n)<<endl;
    }
}