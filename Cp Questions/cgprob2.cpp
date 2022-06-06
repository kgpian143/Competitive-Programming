#include<bits/stdc++.h>
using namespace std ;
int min( int a , int b )
{
    if( a > b)return b ;
    else return a ;
}
int solve( int a , int b )
{
     if( a == b )return 0 ;
     else 
     {
         int count1 ;
         if( a < b ){
             count1 = 1 + solve( a + 1 , b );
         }
         else if( a > b ){
             count1 = 1 + solve( a , b + 1 );
         }
        //  int count1 = 1 + solve( a + 1 , b );
        //  int count2 = 1 + solve( a , b+ 1  );
         int count2 = 1 + solve( a | b , b );
         int mincount = min( count1, count2  );
         return mincount;
     }
}
int main()
{
    int t;
    cin >> t ;
    while(t-- > 0){
        int a , b ;
        cin >> a >> b ;
        cout<<solve(a,b)<<endl;
    }
    return 0;
}