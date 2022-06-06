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
    int minimum;
    int cnt;
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
    //   void clear()
    //   {
    //       if( st == end )return  ;
    //       left->clear() ;
    //       right->clear() ;
    //       delete left ;
    //       delete right ;
    //       st = end = mid = 0 ;
    //   }
    segment ans;
    //   ans.cnt = 0 ;
    segment combine(segment l, segment r)
    {
        segment temp;
        temp.minimum = min(l.minimum, r.minimum);
        if (l.minimum == r.minimum)
            temp.cnt = l.cnt + r.cnt;
        else if( l.minimum <  r.minimum )
            temp.cnt = l.cnt;
        else 
            temp.cnt = r.cnt;
        return temp;
    }

public:
    SegmentTree(int st1, int end1)
    {
        st = st1;
        end = end1;
        mid = (st + end) >> 1;
        ans.cnt = 0;
    }
    void build(vector<int> &v)
    {
        // cout<<1;
        if (st == end)
        {
            ans.minimum = v[st];
            ans.cnt = 1;
            return;
        }
        else
        {
            // cout<<2 ;
            if (!left)
                left = new SegmentTree(st, mid);
            if (!right)
                right = new SegmentTree(mid + 1, end);
            left->build(v);
            right->build(v);
            // ans = min(left->ans , right->ans) ;
            ans = combine(left->ans, right->ans);
        }
    }
    // int getValue( int pos )
    // {
    //     if( st == end )return ans ;
    //     if( mid >= pos )return left->getValue(pos) ;
    //     else return right->getValue(pos) ;
    // }
    void update(int i, int v)
    {
        if (st == end)
        {
            ans.minimum = v;
            ans.cnt = 1;
            return;
        }
        if (mid >= i)
            left->update(i, v);
        else
            right->update(i, v);
        ans = combine(left->ans, right->ans);
    }
    segment getrangemin(int l, int r)
    {
        // if( st == end )return ans;
        if (isOut(l, r))
        {
            segment temp;
            temp.minimum = INT_MAX;
            temp.cnt = 1 ;
            return temp;
        }
        if (isIn(l, r))
        {
            return ans;
        }
        // return min(left->getrangemin(l,r) , right->getrangemin(l , r)) ;
        return combine(left->getrangemin(l, r), right->getrangemin(l, r));
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vi v(n, 0);
    f(i, 0, n) cin >> v[i];
    SegmentTree ST(0, n - 1);
    ST.build(v);
    while (q-- > 0)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i, v;
            cin >> i >> v;
            ST.update(i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << ST.getrangemin(l, r - 1).minimum << " " << ST.getrangemin(l, r - 1).cnt << endl;
        }
    }
    return 0;
}