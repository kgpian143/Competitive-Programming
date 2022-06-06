#include<bits/stdc++.h>
using namespace std ;
unordered_map<char,int> bracket = {{'(', 1},{'[' ,2},{'{',3},{')', -1},{']' ,-2},{'}',-3}} ;
void paranth_match( string s)
{
    stack<char> st ;
    for( char i : s )
    {
        if(bracket[i] > 0 )st.push(i);
        else{
            if(bracket[st.top()]+bracket[i] == 0 )st.pop() ;
            else
            {
                cout<<"No"<<endl;
                return;
            }
        }
    }
    if(!st.empty())
    {
        cout<<"No"<<endl;
                return;
    }
    else 
    {
        cout << "Yes" << endl ;
    }
}
int main()
{
    int n ;
    cin>>n;
    for( int i = 0 ; i < n ; i++ )
    {
        string s ;
        cin >> s ;
        paranth_match(s);
    }
    return 0;
}