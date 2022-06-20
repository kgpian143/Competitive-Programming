#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<vector<bool>> vvb;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<pii> vpii;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define mod 1000000007
#define f(i, a, b) for (int i = a; i < b; i++)
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
const int N = 2e5 + 5;
template <class T>
ostream &operator<<(ostream &os, const vector<T> a)
{
    for (auto ele : a)
        os << ele << " ";
    return os;
}
template <class T>
istream &operator>>(istream &is, vector<T> &a)
{
    for (auto &ele : a)
        is >> ele;
    return is;
}
vector<int> maxset(vector<int> &A)
{
    vector<int> ans;
    int l = -1, r = -1, max_sum = INT_MIN;
    int curr_sum = 0;
    int st = 0;
    int n = A.size();
    int cnt = 0 ;
    for( int i = 0 ; i < n ; i++)
    {
        if( A[i] >= 0 )
        {
            cnt++ ;
            break;
        }
    }
    if( cnt == 0 )return ans ;
    for (int i = 0; i < n; i++)
    {
        if (A[i] < 0)
        {
            if (curr_sum == max_sum && A[i-1] >= 0)
            {
                if (i - st > r - l)
                {
                    l = st;
                    r = i - 1;
                }
            }
            if (curr_sum > max_sum)
            {
                l = st;
                r = i-1;
                max_sum = curr_sum;
            }
            curr_sum = 0;
        }
        else
        {
            if (curr_sum == 0 && A[i-1] != 0)
            {
                st = i;
            }
            curr_sum += A[i];
        }
    }
    if (curr_sum == max_sum)
    {
        if (n - 1 - st > r - l)
        {
            l = st;
            r = n - 1 ;
        }
    }
    if (curr_sum > max_sum )
    {
        l = st;
        r = n-1;
        max_sum = curr_sum;
    }
    for (int j = l; j <= r; j++)
        ans.push_back(A[j]);
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vi v(n, 0);
        f(i, 0, n) cin >> v[i];
        vi ans = maxset(v);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}