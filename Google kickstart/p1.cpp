#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define f(i, a, b) for (int i = a; i < b; i++)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<vector<bool>> vvb;
typedef map<int, int> mii;
typedef map<long long, long long> mll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;

int main()
{
    int t;
    cin >> t;
    int t1 = 1;
    while (t-- > 0)
    {
        int n;
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0, flag = 0;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (c1 == 0)
            {
                if (s[i] <= 'z' && s[i] >= 'a')
                    c1++;
            }
            if (c2 == 0)
            {
                if (s[i] <= 'Z' && s[i] >= 'A')
                    c2++;
            }
            if (c3 == 0)
            {
                if (s[i] <= '9' && s[i] >= '0')
                    c3++;
            }
            if (c4 == 0)
            {
                if (s[i] == '@' || s[i] == '&' || s[i] == '*' || s[i] == '#')
                    c4++;
            }
        }
        if (c1 == 0)
        {
            s.push_back('a');
        }
        if (c2 == 0)
        {
            s.push_back('A');
        }
        if (c3 == 0)
        {
            s.push_back('0');
        }
        if (c4 == 0)
        {
            s.push_back('@');
        }
        while (s.size() < 7)
        {
            s.push_back('a');
        }
        cout << "Case #" << t1 << ": " << s << endl;
        t1++ ;
    }
    return 0;
}