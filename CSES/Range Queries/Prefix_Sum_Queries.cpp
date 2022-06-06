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
struct segment
{
    long long int pref;
    long long int sum;
};

class SegmentTree
{
private:
    SegmentTree *left = NULL;
    SegmentTree *right = NULL;
    int st, end, mid;
    bool isOut(int l, int r)
    {
        return (st > r || end < l);
    }
    bool isIn(int l, int r)
    {
        return (l <= st && end <= r);
    }
    segment ans;
    segment combine(segment l, segment r)
    {
        segment ans1;
        ans1.pref = max(l.pref, r.pref + l.sum);
        ans1.sum = l.sum + r.sum;
        return ans1;
    }

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
            ans.sum = v[st];
            ans.pref = v[st];
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
            ans = combine(left->ans, right->ans);
        }
    }
    
    void update(int i, int v)
    {
        if (st == end)
        {
            ans.sum = v;
            ans.pref = v;
            return;
        }
        if (mid >= i)
            left->update(i, v);
        else
            right->update(i, v);
        ans = combine(left->ans, right->ans);
    }
    segment getrangemaxprefix(int l, int r)
    {
        if (isOut(l, r))
        {
            segment temp;
            temp.pref = 0;
            temp.sum = 0;
            return temp;
        }
        if (isIn(l, r))
        {
            return ans;
        }
        return combine(left->getrangemaxprefix(l, r), right->getrangemaxprefix(l, r));
    }
};
int main()
{
    int n, q;
    cin >> n >> q;
    vi v(n + 1, 0);
    f(i, 0, n) cin >> v[i + 1];
    SegmentTree ST(1, n);
    ST.build(v);
    while (q-- > 0)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i, v;
            cin >> i >> v;
            ST.update(i, v);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << ((ST.getrangemaxprefix(a, b).pref < 0) ? 0 : ST.getrangemaxprefix(a, b).pref) << endl;
        }
    }
    return 0;
}