#include<bits/stdc++.h>
using namespace std ;

int main()
{
      vector<int> v = {1,2,3,4,5};
    for( int i = 0 ;i < v.size() ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    for(auto it = v.begin() ; it != v.end() ; ++it)// auto is a variable data type which set its data type according to assigning
    {
        cout<<(*it)<<endl;//*it contain value
    }
    cout<<endl<<endl;
    for( int value : v )
    {
        cout<<value<<" ";
    }
    cout<<endl;
    vector<pair<int,int> > vp = {{1,3},{2,5},{5,9},{10,3}};
    for( auto value1 : vp)
    {
        cout<<value1.first<<" "<<value1.second<<endl;
    }
    // for( pair<int,int> value1 : vp)
    // {
    //     cout<<value1.first<<" "<<value1.second<<endl;
    // }
    return 0;
}