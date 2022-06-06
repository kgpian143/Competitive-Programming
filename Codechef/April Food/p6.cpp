#include<bits/stdc++.h>
using namespace std ;
int solve( pair<int,int> p1 , pair<int,int> p2 ,pair<int,int> p3 )
{
    if( p1.first == p2.first || p1.first == p3.first || p2.first == p3.first)
    {
         if( p1.second == p2.second || p1.second == p3.second || p2.second == p3.second)
         {
             return 1 ;
         }
    }
    float a , a1 , a2 ;
    if( p1.first == p2.first  || p2.first == p3.first)
    {
        a = 0 ;
    }
    else  a = ((p1.second - p2.second ) * (p2.second - p3.second )*(1.0))/((p1.first - p2.first ) * (p2.first - p3.first )) ;
    if( a == -1)return 1 ;
    if(p1.first == p3.first || p2.first == p3.first) a1 = 0 ;
    else a1 = ((p1.second - p3.second ) * (p3.second - p2.second )*(1.0))/((p1.first - p3.first ) * (p3.first - p2.first )) ;
    if( a1 == -1)return 1 ;
    if( p1.first == p2.first || p1.first == p3.first )a2 = 0 ;
    else a2 = ((p1.second - p3.second ) * (p1.second - p2.second )*(1.0))/((p1.first - p3.first ) * (p1.first - p2.first )) ;
    if( a2 == -1)return 1 ;

    return 0 ;
}
int main()
{
    int t ;
    cin >> t ;
    while( t -- > 0 )
    {
        int n ;
        cin >> n ;
        vector<pair<int,int>> vp ;
        int x , y , cnt = 0;
        for( int i = 0 ; i < n ; i++ )
        {
            cin >> x >> y ;
            vp.push_back(make_pair(x,y));
        }
        for( int i = 0 ; i < n-2 ; i++)
        {
            for( int j = i+1 ; j < n-1 ; j++ )
            {
                for( int k = j + 1 ; k < n ; k++)
                {
                    if( solve(vp[i],vp[j],vp[k]) == 1)cnt++ ;
                }
            }
        }
        cout<<cnt<<endl ;
    }
    return 0;
}
/*
1
5
0 0
1 2
1 0
-1 2
3 1
 
*/