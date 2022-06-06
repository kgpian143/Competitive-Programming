#include <bits/stdc++.h>
using namespace std;
// #define mod 1000000007
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
int mod;
struct segment
{
    long long int a11;
    long long int a12;
    long long int a21;
    long long int a22;
};
segment id;
void printseg(segment s)
{
    cout << s.a11 << " " << s.a12 << endl;
    cout << s.a21 << " " << s.a22 << endl;
    cout << endl;
}
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
    segment combine(segment s1, segment s2)
    {
        segment temp;
        temp.a11 = ((s1.a11 * s2.a11) % mod + (s1.a12 * s2.a21) % mod) % mod;
        temp.a12 = ((s1.a11 * s2.a12) % mod + (s1.a12 * s2.a22) % mod) % mod;
        temp.a21 = ((s1.a21 * s2.a11) % mod + (s1.a22 * s2.a21) % mod) % mod;
        temp.a22 = ((s1.a21 * s2.a12) % mod + (s1.a22 * s2.a22) % mod) % mod;
        return temp;
    }
    segment ans;

public:
    SegmentTree(int st1, int end1)
    {
        st = st1;
        end = end1;
        mid = (st + end) >> 1;
    }
    void build(vector<segment> &v)
    {
        if (st == end)
        {
            ans.a11 = v[st].a11;
            ans.a12 = v[st].a12;
            ans.a21 = v[st].a21;
            ans.a22 = v[st].a22;
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
    // int getValue(int pos)
    // {
    //     if (st == end)
    //         return ans;
    //     if (mid >= pos)
    //         return left->getValue(pos);
    //     else
    //         return right->getValue(pos);
    // }
    // void update(int i, int v)
    // {
    //     if (st == end)
    //     {
    //         ans = v;
    //         return;
    //     }
    //     if (mid >= i)
    //         left->update(i, v);
    //     else
    //         right->update(i, v);
    //     ans = left->ans + right->ans;
    // }
    segment getrangeproduct(int l, int r)
    {
        if (isOut(l, r))
        {
            return id ;
        }
        if (isIn(l, r))
            return ans;
        return combine(left->getrangeproduct(l, r), right->getrangeproduct(l, r));
    }
};

int main()
{
    id.a11 = 1;
    id.a12 = 0;
    id.a21 = 0;
    id.a22 = 1;
    int n, r, m;
    cin >> r >> n >> m;
    mod = r;
    vector<segment> v;
    segment seg0;
    seg0.a11 = 1;
    seg0.a12 = 0;
    seg0.a21 = 0;
    seg0.a22 = 1;
    v.push_back(seg0);
    for (int i = 1; i <= n; i++)
    {
        segment temp;
        int a, b, c, d;
        cin >> a >> b;
        temp.a11 = a;
        temp.a12 = b;
        cin >> c >> d;
        temp.a21 = c;
        temp.a22 = d;
        v.push_back(temp);
    }
    SegmentTree ST(1, n);
    ST.build(v);
    // for( int i = 0 ; i <= n ; i++ )
    // {
    //     printseg(v[i]) ;
    // }
    while (m-- > 0)
    {
        int l, r1;
        cin >> l >> r1;
        printseg(ST.getrangeproduct(l, r1));
    }
    return 0;
}