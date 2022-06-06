#include <bits/stdc++.h>
using namespace std;

void printunomap(unordered_map<int, string> m)
{
    cout << m.size() << endl;
    for (auto it : m)
    {
        cout << it.first << " " << it.second << endl;
    }
}
int main()
{
   // Unordered_maps does not insert in a sorting order 
    unordered_map<int, string> m; 
    m[1] = "abc";
    m[4] = "kdgj";
    m[2] = "cdc";
    m[3] = "cjf";
    m.insert({ 6 ,"vinod"});//O(1)
    printunomap(m);
    auto it = m.find(3); //O(1)
    if (it != m.end())
        m.erase(it);//O(1)
    // if( it == m.end())
    // {
    //     cout<<"No value"<<endl;
    // }
    // else
    // {
    //     cout<<it->first<<" "<<it->second<<endl ;
    // }
    m.clear() ;//clear the all value ;
    printunomap(m);
    // You can't stored pairs in unordered map
    return 0;
}