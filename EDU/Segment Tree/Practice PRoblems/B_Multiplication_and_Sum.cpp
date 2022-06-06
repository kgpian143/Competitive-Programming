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
    long long int val ;
    long long int mult ;
};
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
        if (st == end)
        {
            ans.val = v[st];
            ans.mult = 1 ;
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
            ans.mult = 1;
            ans.val = left->ans.val + right->ans.val ;
        }
    }
    void propagate()
    {
        if( st == end)
        {
            ans.val = (ans.val*ans.mult)%mod ;
            ans.mult = 1 ;
        }
        else 
        {
            ans.val = (ans.val*ans.mult)%mod ;
            left->ans.mult = (left->ans.mult * ans.mult)%mod ;
            right->ans.mult = (right->ans.mult * ans.mult) % mod;
            ans.mult =  1 ;
        }
    }
    void update(int val, int l, int r)
    {
        propagate() ;  
        if (isOut(l, r))
            return;

        if (isIn(l, r))
        {
            ans.mult = (val * ans.mult)%mod ;
            propagate() ;
            return ;
        }
        else
        {
            left->update(val, l, r);
            right->update(val, l, r);
            ans.val =  (left->ans.val  +  right->ans.val)%mod  ;
        }
    }
    long long int getValue(int pos)
    {
        if (st == end)
            return ans.val * ans.mult;
        if (ans.mult != 1)
        {
            propagate() ;
        }
        if (mid >= pos)
            return left->getValue(pos);
        else
            return right->getValue(pos);
    }
    long long int getrangesum(int l, int r)
    {
        propagate() ;
        if (isOut(l, r))
            return 0;
        
        if( st == end )
        {
            return ans.val;
        }
        if (isIn(l, r))
        {
            return ans.val ;
        }    
        return (left->getrangesum(l, r) + right->getrangesum(l, r))%mod;
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vi v(n, 1);
    SegmentTree ST(0, n - 1);
    ST.build(v);
    while (q-- > 0)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            ST.update(v, l, r - 1);
        }
        else
        {
            int l , r ;
            cin>>l>>r;
            cout<<ST.getrangesum(l,r-1)<<endl;
            // cout<<ST.getValue(l)<<ST.getValue(r-1)<<endl ;
            // cout<<ST.getValue(l)<<endl;
        }
    }
    return 0;
}