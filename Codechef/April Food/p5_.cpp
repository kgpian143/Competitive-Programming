#include<bits/stdc++.h>
using namespace std ;

int solve( pair<int,int> p1 , pair<int,int> p2 ,pair<int,int> p3 )
{
    long long int d1  , d2 ,  d3  ;
    d1 = ((p1.first - p2.first)*(p1.first - p2.first)+(p1.second - p2.second)*(p1.second - p2.second)) ;
    d2 = ((p3.first - p2.first)*(p3.first - p2.first)+(p3.second - p2.second)*(p3.second - p2.second));
    d3 = ((p1.first - p3.first)*(p1.first - p3.first)+(p1.second - p3.second)*(p1.second - p3.second));
    if( (d1 + d2 == d3) || (d1 + d3 == d2) || (d3 + d2 == d1) )return 1 ;
    // pair<float,float> f1 ,  f2 , f3 ;
    // f1 = make_pair((p1.first+p2.first)*(0.5) ,(p1.second+p2.second)*(0.5) ); 
    // f2 = make_pair((p3.first+p2.first)*(0.5) ,(p3.second+p2.second)*(0.5) ); 
    // f3 = make_pair((p1.first+p3.first)*(0.5) ,(p1.second+p3.second)*(0.5) ); 
    // dc1 =  sqrt((f1.first - p3.first)*(f1.first - p3.first)+(f1.second - p3.second)*(f1.second - p3.second));
    // dc2 =  sqrt((f2.first - p1.first)*(f2.first - p1.first)+(f2.second - p1.second)*(f2.second - p1.second));
    // dc3 =  sqrt((f3.first - p2.first)*(f3.first - p2.first)+(f3.second - p2.second)*(f3.second - p2.second));
    // if( 2*dc1 == d1 ||  2*dc2 == d2 ||  2*dc3 == d3  )return 1 ;
    else return 0 ;
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