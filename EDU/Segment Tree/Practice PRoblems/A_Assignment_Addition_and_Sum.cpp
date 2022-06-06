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
    long long int assign ;
    long long int add ;
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
            ans.assign = -1 ;
            ans.add = 0 ;
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
            ans.assign = -1;
            ans.add = 0 ;
            ans.val =  left->ans.val + right->ans.val  ;
        }
    }
    void propagate()
    {
        if( st == end)
        {
            ans.val = ans.assign ;
            ans.assign = -1 ;
            ans.add = 0 ;
        }
        else 
        {
            ans.val = ans.assign * ( end - st + 1) ;
            left->ans.assign = ans.assign ;
            right->ans.assign = ans.assign ;
            ans.assign = -1 ;
            // ans.add = 0 ;
        }
    }
    void propagate1()
    {
        if( st == end)
        {
            ans.val += ans.add ;
            ans.add = 0 ;
        }
        else 
        {
            ans.val += ans.add ;
            left->ans.add += ans.add ;
            right->ans.add += ans.add ;
            ans.add = 0 ;
        }
    }
    void update1(int val, int l, int r)
    {
        // cout<<3;
        if(ans.assign != -1)
        {
            // cout<<"assigne"<<ans.assign<<endl ;
            propagate() ; 
        } 
        else if( ans.add != 0 )
        {
            // cout<<"add"<<ans.add<<endl ;
            propagate1();
        }
        if (isOut(l, r))
            return;
        if (isIn(l, r))
        {
            ans.assign = val ;
            return ;
        }
        else
        {
            left->update1(val, l, r);
            right->update1(val, l, r);
            ans.val = ( left->ans.val + right->ans.val  ) ;
        }
    }
    void update2(int val, int l, int r)
    {
        // cout<<1;
        if(ans.assign != -1)
        {
            cout<<"assigne"<<ans.assign<<endl ;
            propagate() ; 
        } 
        else if( ans.add != 0 )
        {
            cout<<"add"<<ans.add<<endl ;
            propagate1();
        }
        // cout<<2;
        if (isOut(l, r))
            return;
        if (isIn(l, r))
        {
            ans.add += val ;
            return ;
        }
        else
        {
            left->update2(val, l, r);
            right->update2(val, l, r);
            ans.val = ( left->ans.val + right->ans.val  ) ;
        }
    }
    long long int getValue(int pos)
    {
        if (st == end)
            return ans.val;
        if (ans.assign != -1)
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
        if(ans.assign != -1)propagate() ;
        else if( ans.add != 0 )propagate1();
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
        return (left->getrangesum(l, r) + right->getrangesum(l, r));
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n, q;
    cin >> n >> q;
    vi v(n, 0);
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
            ST.update1(v, l, r - 1);
        }
        else if (t == 2)
        {
            int l, r, v;
            cin >> l >> r >> v;
            ST.update2(v, l, r - 1);
        }
        else 
        {
            int l , r ;
            cin>>l>>r;
            cout<<ST.getrangesum(l,r-1)<<endl;
            // cout<<ST.getValue(l)<<endl;
        }
    }
    return 0;
}