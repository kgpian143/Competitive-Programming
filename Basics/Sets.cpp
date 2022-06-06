#include<bits/stdc++.h>
using namespace std ;

void printset( set<string> s)
{
    for( auto i : s)
    {
        cout<<i<<endl ;
    }
}
int main()
{
    set<string> s ;
    s.insert("abc");//O(logn)
    s.insert("abc");//O(logn)
    s.insert("argvtc");
    s.insert("argvtc");
    s.insert("avfv");
    s.insert("bvffv");
    printset(s);
    cout<<endl;
    auto it = s.find("abc");//O(logn)
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