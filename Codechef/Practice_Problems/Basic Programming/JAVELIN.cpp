#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m, x;
        cin >> n >> m >> x;
        vector<pair<int, int>> vp;
        vector<bool> v1(n+1,false);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            int ld;
            cin >> ld;
            if (ld >= m)
            {
                vp.push_back(make_pair(-ld, i));
                cnt++;
            }
            else
            {
                vp.push_back(make_pair(-ld, i));
            }
        }
        sort(vp.begin(), vp.end());
        if (cnt < x)
        {
            cout << x;
            for( int i = 0 ; i < x ; i++ )v1[vp[i].second] = true ;
            for( int i = 0 ; i <= n ; i++ )
            {
                if( v1[i] == true)cout<<" "<<i;
            }
            cout<<endl ;
        }
        else
        {
            cout << cnt;
            for( int i = 0 ; i < cnt ; i++ )v1[vp[i].second] = true ;
            for( int i = 0 ; i <= n ; i++ )
            {
                if( v1[i] == true)cout<<" "<<i;
            }
            cout<<endl ;
        }
    }
    return 0;
}