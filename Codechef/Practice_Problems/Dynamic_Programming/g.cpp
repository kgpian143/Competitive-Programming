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
        vi v(n, 0);
        f(i, 0, n) cin >> v[i];
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            // cnt += min( v[i] , n - v[i] ) ;
            if (v[i] <= n)
            {
                int cnt1 = 0 ;
                int k1 = min(v[i] - 1, i);
                int k2 = min(v[i] - 1, n - i - 1);
                if (k1 < k2)
                {
                    cnt1 = min(k1 + 1, n - v[i] + 1);
                }
                else
                {
                    cnt1 = min(k2 + 1, n - v[i] + 1);
                }
                p = 
                for( int j = i-1 ; j >=  0 && j >= i - v[i] + 1  ; j-- )
                {
                }
                cout << cnt << " ";
            }
        }
        cout << cnt << endl;
    }
    return 0;
}