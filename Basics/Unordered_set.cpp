#include<bits/stdc++.h>
using namespace std ;

void printset( unordered_set<string> s)
{
    for( auto i : s)
    {
        cout<<i<<endl ;
    }
}
int main()
{
    unordered_set<string> s ;
    s.insert("abc");//O(1)
    s.insert("abc");//O(1)
    s.insert("argvtc");
    s.insert("argvtc");
    s.insert("avfv");
    s.insert("bvffv");
    printset(s);
    cout<<endl;
    auto it = s.find("abc");//O(1)
    if( it != s.end())
    {
        cout<<(*it)<<endl<<endl ;
    }
    s.erase(it);//erase at only it index
    printset(s);
    cout<<endl;
    s.erase("argvtc");//erase all string with key "argvtc"
    printset(s);
    return 0;
}