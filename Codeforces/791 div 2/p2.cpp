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
            ans.val =  left->ans.val + right->ans.val  ;
        }
    }
    void propagate()
    {
        if( st == end)
        {
            ans.val = ans.assign ;
            ans.assign = -1 ;
        }
        else 
        {
            ans.val = ans.assign * ( end - st + 1) ;
            left->ans.assign = ans.assign ;
            right->ans.assign = ans.assign ;
            ans.assign = -1 ;
        }
    }
    void update(int val, int l, int r)
    {
        if(ans.assign != -1)propagate() ;  
        if (isOut(l, r))
            return;
        if (isIn(l, r))
        {
            ans.assign = val ;
            propagate() ;
            return ;
        }
        else
        {
            left->update(val, l, r);
            right->update(val, l, r);
            ans.val = ( left->ans.val + right->ans.val  ) ;
        }
    }
    long long int getrangesum(int l, int r)
    {
        if(ans.assign != -1)propagate() ;
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
    int n, q;
    cin >> n >> q;
    vi v(n, 0);
    f(i , 0 , n )cin>>v[i] ;
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
            ST.update(v , i-1 , i-1);
            cout<<ST.getrangesum(0,n-1)<<endl ;
        }
        else
        {
            int v;
            cin >> v;
            ST.update( v , 0 , n-1) ;
            cout<<ST.getrangesum(0,n-1)<<endl;
        }
    }
    return 0;
}