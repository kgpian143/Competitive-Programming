#include<bits/stdc++.h>
using namespace std ;

bool cmpint( int x , int y )
{
    return x > y ;
}
bool cmppair ( pair<int,int> x , pair<int,int> y )
{
    if( x.first != y.first )return x.first > y.first ;
    else
       return x.second > y.second ;
}
int main()
{
    int n ;
    cin >> n ;
    int a[n] ;
    for( int i = 0 ; i < n ; i++ )
    {
        cin >> a[i] ;
    }
    sort( a , a+n );
    for( int i = 0 ; i < n ; i++ )
    {
        cout << a[i] << " ";
    }
    cout << endl ;
    sort( a , a+n ,cmpint);
    for( int i = 0 ; i < n ; i++ )
    {
        cout << a[i] << " ";
    }
    // vector<pair<int,int>> vp(n) ;
    // for( int i = 0 ; i < n ; i++ )
    // {
    //     cin >> vp[i].first >> vp[i].second ;
    // } 
    // sort( vp.begin() , vp.end()) ;
    // for( int i = 0 ; i < n ; i++ )
    // {
    //     cout << vp[i].first << " " << vp[i].second << endl;
    // }
    // sort( vp.begin() , vp.end() , cmppair);
    // cout << endl ;
    // for( int i = 0 ; i < n ; i++ )
    // {
    //     cout << vp[i].first << " " << vp[i].second << endl;
    // }
    return 0;
}