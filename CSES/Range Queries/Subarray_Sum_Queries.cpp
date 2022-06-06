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
    long long int suff;
    long long int sum;
    long long int max_seg;
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
        segment ans1;
        ans1.suff = max(r.suff, r.sum + l.suff);
        ans1.pref = max(l.pref, r.pref + l.sum);
        ans1.max_seg = max(l.max_seg, r.max_seg);
        ans1.max_seg = max(ans1.max_seg, l.suff + r.pref);
        ans1.sum = l.sum + r.sum;
        return ans1;
    }

public:
    SegmentTree(int st1, int end1)
    {
        st = st1;
        end = end1;
        mid = (st + end) >> 1;
        // ans.cnt = 0;
    }
    void build(vector<int> &v)
    {
        // cout<<1;
        if (st == end)
        {
            ans.sum = v[st];
            ans.pref = v[st];
            ans.suff = v[st];
            ans.max_seg = v[st];
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
            ans.sum = v;
            ans.pref = v;
            ans.suff = v;
            ans.max_seg = v;
            return;
        }
        if (mid >= i)
            left->update(i, v);
        else
            right->update(i, v);
        ans = combine(left->ans, right->ans);
    }
    segment getrangemaxseg(int l, int r)
    {
        // if( st == end )return ans;
        if (isOut(l, r))
        {
            segment temp;
            temp.max_seg = 0;
            temp.pref = 0;
            temp.suff = 0;
            temp.sum = 0;
            return temp;
        }
        if (isIn(l, r))
        {
            return ans;
        }
        // return min(left->getrangemaxseg(l,r) , right->getrangemaxseg(l , r)) ;
        return combine(left->getrangemaxseg(l, r), right->getrangemaxseg(l, r));
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vi v(n + 1, 0);
    f(i, 0, n) cin >> v[i+1];
    SegmentTree ST(1, n);
    ST.build(v);
    while (q-- > 0)
    {
        int i, v;
        cin >> i >> v;
        ST.update(i, v);
        cout << ((ST.getrangemaxseg(1, n).max_seg < 0) ? 0 : ST.getrangemaxseg(1, n ).max_seg) << endl;
    }
    return 0;
}