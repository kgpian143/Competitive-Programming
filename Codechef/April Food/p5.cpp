#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int c1 = 0, c2 = 0, n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (a == 1)
                c1++;
            else
                c2++;
        }
        // cout << "c1 " << c1 << "c2 " << c2 << endl;
        if (c1 == 0 || c2 == 0)
            cout << "NO" << endl;
        else if (c1 == c2)
            cout << "YES" << endl;
        else if (abs(c1 - c2) % 2 == 0 && c1 % 2 == 0)
        {
            if (abs(c1 - c2) > 2)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
        else if (abs(c1 - c2) % 2 == 1)
        {
            if (abs(c1 - c2) > 1)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}