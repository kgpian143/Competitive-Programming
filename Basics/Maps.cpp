#include <bits/stdc++.h>
using namespace std;

void printmap(map<int, string> m)
{
    cout << m.size() << endl;
    for (auto it : m)
    {
        cout << it.first << " " << it.second << endl;
    }
}
int main()
{
    // Maps stores keys in a sorted order
    map<int, string> m; //it stores keys in asscending order with time compl O(logn)
    m[1] = "abc";
    m[4] = "akdgj";
    m[2] = "cdc";
    m[3] = "cjf";
    printmap(m);
    cout<<m.size() ;
    auto it = m.find(3); //O(logn)
    // if (it != m.end())
    //     m.erase(it);
    // // if( it == m.end())
    // // {
    // //     cout<<"No value"<<endl;
    // // }
    // // else
    // // {
    // //     cout<<it->first<<" "<<it->second<<endl ;
    // // }
    
    // printmap(m);
    // m.clear() ;//clear the all value ;
    printmap(m);
    cout<<"m[6] "<<m[6] <<" plm" ;
    return 0;
}