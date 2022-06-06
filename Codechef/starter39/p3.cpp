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
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int cnt = 0, cnt1 = 0;
        if ((n & 1) == 0)
        {
            int i = 4, j = 6 ;
            while (cnt < n)
            {
                cout << i << " " << i + 1 << " ";
                i += 4;
                cnt += 2;
            }
            cout << endl;
            while (cnt1 < n)
            {
                cout << j << " " << j + 1 << " ";
                j += 4 ;
                cnt1 += 2 ;
            }
            cout<<endl;
        }
        else
        {
            int i = 4, j = 6 ;
             while (cnt < n - 1)
            {
                cout << i << " " << i + 1 << " ";
                i += 4;
                cnt += 2;
            }
            cout <<i<< endl;
            while (cnt1 < n - 1)
            {
                cout << j << " " << j + 1 << " ";
                j+= 4 ;
                cnt1 += 2 ;
            }
            cout<<j<<endl;
        }
    }
    return 0;
}