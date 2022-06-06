#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n ;
    cin >> n ;
    // int a[n] ;
    // for( int i = 0 ; i < n ; i++ )
    // {
    //     cin >> a[i] ;
    // }
    // sort( a , a+n );
    // for( int i = 0 ; i < n ; i++ )
    // {
    //     cout << a[i] << " ";
    // }
    vector<int> v(n) ;
    for( int i = 0 ; i < n ; i++ )
    {
        cin >> v[i] ;
    }
    sort( v.begin() , v.end());
    for( int i = 0 ; i < n ; i++ )
    {
        cout << v[i] << " ";
    }
    return 0;
}