#include<bits/stdc++.h>
using namespace std ;

int main()
{
    
    int t ; 
    
    cin >>  t ;
    while( t-- > 0 )
    {
        int m , n , r , c ;
        char board[50][50] ;
        cin >> m >> n >> r >> c ;
        int flag1 = 0  , flag2 = 0 , flag3 = 0 ; 
        for( int i = 1 ; i <= m ; i++)
        {
            for( int j = 1 ; j <= n ; j++)
            {
                cin >> board[i][j] ;
                if( r == i )
                {
                     
                     if ( i == r && j == c )
                     {
                         if( board[i][j] == 'B')flag1++ ;
                     }
                     else if( board[i][j] = 'B')flag2++ ;
                }
                if( j == c )
                {
                     if( board[i][j] == 'B')flag2++ ;
                }
                else if( board[i][j] == 'B')flag3++;
            }
        }
       if( flag1 != 0 )
       {
           cout << 0 << endl;
        //    return 0 ;
       }
       else if( flag2 != 0 )
       {
           cout << 1 << endl;
        //    return 0 ;
       }
       else if( flag3 != 0 )
       {
           cout << 2 << endl ;
       }
       else 
       {
           cout << -1 <<endl ;
        //    return 0 ;
       }
       
    }
    return 0;
}
// 1 0 