#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    multiset<int> st;
    vector<int> v1(m);

    for (int i = 0; i < n; i++)
    {
        int a ;
        cin>>a ;
        st.insert(a) ;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> v1[i];
    }
    vector<int> ans ;
    // sort(v.begin(), v.end());
    for (int i = 0; i < m; i++)
    {
        // vector<int>::iterator it = lower_bound(v.begin(), v.end(), v1[i]);
        // if (it != v.begin() && *it != v1[i])
        // {
        //     it--;
        //     if (*it <= v1[i])
        //     {
        //         cout << *it << endl;
        //         v.erase(it);
        //     }
        //     else
        //     {
        //         cout << -1 << endl;
        //     }
        // }
        // else if (*it == v1[i])
        // {
        //     cout << *it << endl;
        //     v.erase(it);
        // }
        // else if (it == v.begin())
        // {
        //     cout << -1 << endl;
        // }
        // if( v1[i] < v[0])
        if( st.size() == 0 )
        {
            ans.push_back(-1) ;
            continue;
        }
        if( v1[i] < *st.begin())ans.push_back(-1) ;
        else 
        {
            auto it = st.lower_bound(v1[i]) ;
            if( it == st.end() || *it > v1[i])
            {
                ans.push_back(*(--it)) ;
            }
            else ans.push_back(*it) ;
            st.erase(it) ;
        }
    }
    for( auto it : ans)cout<<it<<" ";    return 0;
}