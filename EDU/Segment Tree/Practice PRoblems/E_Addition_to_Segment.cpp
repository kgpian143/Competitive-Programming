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

class SegmentTree
{
private:
    SegmentTree *left = NULL;
    SegmentTree *right = NULL;
    int st, end, mid;
    bool isOut(int l, int r)
    {
        return (r < st || end < l);
    }
    bool isIn(int l, int r)
    {
        return (l <= st && end <= r);
    }
    long long int ans;

public:
    SegmentTree(int st1, int end1)
    {
        st = st1;
        end = end1;
        mid = (st + end) >> 1;
    }
    void build(vector<int> &v)
    {
        if (st == end)
        {
            ans = v[st];
            return;
        }
        else
        {
            if (!left)
                left = new SegmentTree(st, mid);
            if (!right)
                right = new SegmentTree(mid + 1, end);
            left->build(v);
            right->build(v);
            ans = 0;
        }
    }
    long long int getValue(int pos)
    {
        if (st == end)
            return ans;
        if (ans != 0)
        {
            left->ans += ans;
            right->ans += ans;
            ans = 0;
        }
        if (mid >= pos)
            return left->getValue(pos);
        else
            return right->getValue(pos);
    }
    void update(int val, int l, int r)
    {
        if (isOut(l, r))
            return;
        if (isIn(l, r))
        {
            ans += val;
        }
        else if (st == end)
        {
            ans += val;
        }
        else
        {
            left->update(val, l, r);
            right->update(val, l, r);
        }
    }
    long long int getrangesum(int l, int r)
    {
        if (isOut(l, r))
            return 0;
        if (isIn(l, r))
            return ans;
        return left->getrangesum(l, r) + right->getrangesum(l, r);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vi v(n, 0);
    // f(i, 0, n) cin >> v[i];
    SegmentTree ST(0, n - 1);
    ST.build(v);
    while (q-- > 0)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i, l, r, v;
            cin >> l >> r >> v;
            ST.update(v, l, r - 1);
        }
        else
        {
            int i;
            cin >> i;
            cout << ST.getValue(i) << endl;
        }
    }
    return 0;
}