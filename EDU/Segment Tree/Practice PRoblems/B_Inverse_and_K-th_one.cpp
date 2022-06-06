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
    int val ;
    int assign ;
};
class SegmentTree
{
private:
    SegmentTree *left = NULL;
    SegmentTree *right = NULL;

    bool isOut(int l, int r)
    {
        return (r < st || end < l);
    }
    bool isIn(int l, int r)
    {
        return (l <= st && end <= r);
    }
    int st, end, mid;
    segment ans;

public:
    SegmentTree(int st1, int end1)
    {
        st = st1;
        end = end1;
        mid = (st + end) >> 1;
    }
    void build(vector<int> &v)
    {
        // cout<<1;
        if (st == end)
        {
            ans.val = 0;
            ans.assign = 0 ;
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
            ans.val = 0 ;
            ans.assign = 0 ;
        }
    }
    void propagate()
    {
        if( st == end)
        {
            ans.val ^= 1 ;
            ans.assign = 0 ;
        }
        else 
        {
            ans.val = ( end - st + 1 - ans.val) ;
            left->ans.assign ^= 1 ;
            right->ans.assign ^= 1 ;
            ans.assign ^= ans.assign ;
        }
    }
    int getValue(int k)
    {
        if( ans.assign != 0 )propagate() ;
        if (st == end)
        {
            // cout<<ans.val;
            return end;
        }
        if( left->ans.assign != 0 )left->propagate() ;
        if( right->ans.assign != 0 )right->propagate() ;
        if (k <= left->ans.val)
            return left->getValue(k);
        else
            return right->getValue(k - left->ans.val);
    }
    void update(int l, int r)
    {
        if(ans.assign != 0)propagate() ;  
        if (isOut(l, r))
            return;
        if (isIn(l, r))
        {
            ans.assign ^= 1 ;
            propagate() ;
            return ;
        }
        else
        {
            left->update( l, r);
            right->update( l, r);
            ans.val = ( left->ans.val + right->ans.val  ) ;
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vi v(n, 0);
    // f(i, 0, n) cin >> v[i];
    SegmentTree ST(0, n - 1);
    ST.build(v);
    while (m-- > 0)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int l , r ;
            cin >> l >> r;
            ST.update(l , r-1);
            // v[i] = v[i] ^ 1
        }
        else
        {
            int i;
            cin >> i;
            cout << ST.getValue(i + 1) << endl;
            // ST.print();
            // cout<<endl;
        }
    }
}