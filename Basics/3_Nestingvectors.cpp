#include<bits/stdc++.h>
using namespace std ;
void printvec( vector<pair< int,int >>v)
{
    cout<<"size : "<<v.size()<<endl;
    for( int i = 0 ; i < v.size() ; i++) 
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    cout<<endl;
}
void printvec2( vector<int> v)
{
    cout<<"size : "<<v.size()<<endl;
    for( int i = 0 ; i < v.size() ; i++) 
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    // vector of pairs 
    vector< pair< int,int > > v = {{1,2} ,{2,4} , {2,5}};
    printvec(v);
    v.push_back({1,6});
    v.push_back({1,6});
    v.push_back({1,6});
    printvec(v);
     //array of vectors 
     int n ;
     cin>>n;
     vector<int> v1[n] ; // array of vectors of size n ;
     for( int i = 0 ; i < n ; i++)
     {
         int k ;
         cout<<"vector "<<i+1<<" : ";
         cin>>k ;
         for( int j = 0 ; j < k ; j++ )
         {
             int x ;
             cin>>x;
             v1[i].push_back(x);
         }
     }
     for( int i = 0 ; i < n ; i++)
     {
         printvec2(v1[i]);
     }
     //vector of vectors : 2d array which having changeble size 
     vector< vector<int> > v0 ;
     int n ;
     cin>>n ;
     for( int i = 0 ; i < n ; i++ )
     {
         int x ;
         vector<int> temp ;
         cin>>x ;
         for( int i = 0 ; i < x  ; i++)
         {
             int a ;
             cin>>a;
             temp.push_back(a);
         }
         v0.push_back(temp);
     }
     for( int i = 0 ; i< v.size() ; i++ )
     {
         printvec2(v0[i]);
     }
    return 0;
}