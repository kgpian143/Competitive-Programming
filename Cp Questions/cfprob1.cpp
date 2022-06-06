#include <bits/stdc++.h>
using namespace std;
void solve(string s, int n)
{
    if (n > 2)
    {
        cout << "NO" << endl;
        return;
    }
    else if (n == 1 || n == 0)
    {
        cout << "YES" << endl;
        return;
    }
    else
    {
        if (s[0] == s[1])
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            cout << "YES" << endl;
            return;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int length;
        cin >> length;
        string s;
        cin >> s;
        solve(s, length);
    }
    return 0;
}