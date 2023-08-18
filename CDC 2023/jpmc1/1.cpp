#include<bits/stdc++.h>
using namespace std ;

int main()
{
    string s ;
    cin >> s ;
    stack<char> st ;

    for( auto it : s )
    {
        if( st.empty())
        {
            st.push(it);
        }
        else 
        {
            if( st.top() == it )st.pop() ;
            else st.push(it);
        }
    }

    string ans ;
    while( !st.empty())
    {
        ans.push_back(st.top());
        st.pop() ;
    }
    reverse( ans.begin() , ans.end());
    cout << ans << endl ;
    return 0;
}