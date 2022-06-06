#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int sum = accumulate(v.begin(), v.end(), 0);
        sort(v.begin(), v.end());
        float mean = float(sum) / n;
        long long int cnt = 0;
        int ind;
        for (int i = 0; i < n; i++)
        {
            if (v[i] >= mean)
            {
                ind = i;
                break;
            }
        }
        // if (ind == 0)
        // {
        //     cnt = (n * (n - 1)) / 2;
        // }
        // else
        // {
        for (int i = 0; i < n-1; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (i == j)continue;
                if (2 * mean == float(v[i] + v[j]) )
                {
                    cnt++;
                    // break;
                }
                else if (  2 * mean  < float(v[i] + v[j]))
                {
                    // cnt++ ;
                    break;
                }
            }
        }
        // int a = 0;
        // for (int i = 0; i < n; i++)
        //     if (v[i] == mean)
        //         a++;
        // if (a > 2)
        //     cnt += ((a - 2) * (a - 1)) / 2;
        // cnt += ((a) * (a - 1)) / 2;
        cout << cnt << endl;
    }
    return 0;
}