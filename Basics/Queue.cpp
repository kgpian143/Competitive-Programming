#include<bits/stdc++.h>
using namespace std ;
void printqueue( queue<int> q)
{
    while( !q.empty())
    {
        int a = q.front() ;
        cout<<a<<" ";
        q.pop() ;
    }
}
int main()
{
    queue<int> q ;
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    printqueue(q);
    return 0;
}