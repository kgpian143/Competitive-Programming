#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
const int N = 1e6 + 7;
int fact[N];
bool isgood(int n, int a, int b, int i)
{
    long long int k = i * a + b * (n - i);
    while (k > 0)
    {
        if (k % 10 == a || k % 10 == b)
        {
            k = k / 10;
        }
        else
            return false;
    }
    return true;
}
int binaryexp_(int n, int k)
{
    int ans = 1;
    while (k > 0)
    {
        if (k & 1)
        {
            ans = (ans * 1LL * n) % mod;
        }
        n = (n * 1LL * n) % mod;
        k >>= 1;
    }
    return ans;
}

int main()
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = (fact[i - 1] * 1LL * i) % mod;
    }
    int n, a, b;
    cin >>a>>b>> n;
    int total = 0;
    for (int r = 0; r <= n; r++)
    {
        if (isgood(n, a, b, r))
        {
            int ans = fact[n];
            int den = (fact[n - r] * 1LL * fact[r]) % mod;
            ans = (ans * 1LL * binaryexp_(den, mod - 2)) % mod;
            // cout << n << " C " << r << " : " << ans << endl;
            total = (total + ans) % mod;
        }
    }
    cout<<total;
    return 0;
}