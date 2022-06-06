#include<bits/stdc++.h>
using namespace std ;
void printvec( vector<int>v)
{
    cout<<"size : "<<v.size()<<endl;
    for( int i = 0 ; i < v.size() ; i++) 
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void addnum( vector<int> & vp , int x )
{
    vp.push_back(x);
    return ;
}
int main()
{
    vector<int>v;
    // for( int i = 0 ; i < n ; i++)
    // {
    //     int a ;
    //     cin>>a ;
    //     v.push_back(a);
    //     printvec(v);        
    // }
    v.push_back(2);
    // printvec(v);
    v.push_back(-9);
    // printvec(v);
    v.push_back(56);
    v.push_back(46);
    printvec(v);
    // v.pop_back();
    
    printvec(v);
    addnum(v,5);
    printvec(v);
    // auto it = v.begin() ;
    // // v.erase(it + 3) ;
    // printvec(v);
    // vector<int> v2  = v ;// copy of vector v 
    // cout<<"v2 : ";
    // printvec(v2);
    // vector<int> v3(10);//insert 10 elements with value 0
    // cout<<"v3 : ";
    // printvec(v3);
    // vector<int> v4(10 , 3);//insert 10 elements with value 3
    // cout<<"v4 : ";
    // printvec(v4);
    return 0;
}