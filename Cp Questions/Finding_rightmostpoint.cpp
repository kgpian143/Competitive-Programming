#include<bits/stdc++.h>
using namespace std ;
pair<int,int> bp ;
bool cmp( pair<float,float> a , pair<float,float> b   )
{
    float c1 , c2 ;
    a.first = a.first - bp.first ;
    b.first = b.first - bp.first ;
    a.second = a.second - bp.second ;
    b.second = b.second - bp.second ;
    c1 = a.first/sqrt(a.first*a.first + a.second*a.second) ;
    c2 = b.first/sqrt(b.first*b.first + b.second*b.second) ;
    if( c1 == c2 )return(sqrt(a.first*a.first + a.second*a.second) > sqrt(b.first*b.first + b.second*b.second) );// when points are at same angle then it take the more distant point before than less distant point
    return c1 > c2 ;
}
int main()
{
    int n ;
    cin>> n;
    vector<pair<float,float>> point(n) ;
    for( int i = 0 ; i < n ; i++)
    {
        cin >> point[i].first>>point[i].second;
    }
    auto k = point.begin() ;//Declaring iterator which is used for finding bottom point 
    for( auto it = point.begin() ; it < point.end() ; it++)
    {
        if(it->second < k->second)k = it ;
    }
    bp.first = k->first ;
    bp.second = k->second ;// Storing the bottom point in global variable which is used in comparator function
    cout <<endl;
    point.erase(k);
    sort(point.begin(),point.end() , cmp );
      for( auto it : point)
    {
        cout << it.first << " " << it.second << endl ;
    }
    return 0;
}