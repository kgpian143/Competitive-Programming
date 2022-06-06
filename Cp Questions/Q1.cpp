#include<bits/stdc++.h>
using namespace std ;
void printmap( map<string,int> m)
{
    for(auto it : m)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
} 
int main()
{
    map<string,int> m ;
    int n ;
    cin>>n;
    while( n-- > 0 )
    {
        string s ;
        cin>>s;
        m[s]++ ;
    }
    printmap(m);
    return 0;
}