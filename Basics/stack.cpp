#include<bits/stdc++.h>
using namespace std ;
void printstack( stack<int> s)
{
    while( !s.empty())
    {
        int a = s.top() ;
        cout<<a<<" ";
        s.pop() ;
    }
}
int main()
{
    stack<int> s ;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    printstack(s);
    return 0;
}