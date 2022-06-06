#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while( t -- > 0 )
    {
        int n ;
        cin >> n ; 
        vector<int> A(n+1) ;
        A[0] = 0 ;
        for( int i = 1 ; i <= n ; i++ )
        {
            cin >> A[i] ;
        }
        vector<int> B(n) ;
        for( int i = 0 ; i < n ; i++ )
        {
            cin >> B[i] ;
        }
        int cnt = 0;
        for( int i = 1 ; i <= n ; i++)
        {
            if((A[i] - A[i-1]) >= B[i-1]  )cnt++ ;
        }
        cout << cnt << endl ;
    }
    return 0;
}