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
    vector< int > :: iterator it = v.begin() ; // iterater declaration with assigning it 1st pointer of vector
    // iterator basically a pointer and we have to declare it with specific data type , for which we have to iterate . 
    for( it = v.begin() ; it != v.end() ; ++it)
    {
        cout<<(*it)<<endl;//*it contain value
    }
    return 0;
}
/*
 Important : it++ take the pointer to next vector value it + 1 take the pointer to next address , so it is important for maps and sets;
 */