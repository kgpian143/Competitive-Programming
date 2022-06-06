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
const int N = 2e5 + 5;
long long int table[4 * N];

void build(vector<int> &v, int ind, int st, int se)
{
    if (st == se)
    {
        table[ind] = v[st];
    }
    else
    {
        int tm = (st + se) / 2;
        build(v, ind * 2, st, tm);
        build(v, ind * 2 + 1, tm + 1, se);
        table[ind] = max(table[ind * 2], table[ind * 2 + 1]);
    }
}
int maximum(int v, int st, int se, int l, int r)
{
    if (l > r)
        return INT_MIN;
    if (l == st && r == se)
    {
        return table[v];
    }
    int tm = (st + se) / 2;
    return max(maximum(v * 2, st, tm, l, max(r, tm)), maximum(v * 2 + 1, tm + 1, se, max(l, tm + 1), r));
}

void update(int i, int st, int se, int pos, int new_val)
{
    if (st == se)
    {
        table[i] = new_val;
    }
    else
    {
        int tm = (st + se) / 2;
        if (pos <= tm)
            update(i * 2, st, tm, pos, new_val);
        else
            update(i * 2 + 1, tm + 1, se, pos, new_val);
        table[i] = max(table[i * 2], table[i * 2 + 1]);
    }
}
int findhotel(int ind, int st, int se, int r)
{
    // if( r > table[ind] ) return 0 ;
    if (st == se)
    {
        // update(ind, st, se, st, table[ind] - r);
        return st;
    }
    int mid = (st + se) / 2;
    if (table[2 * ind] >= r )
        return findhotel(2 * ind, st, mid, r);
    else 
        return findhotel(2 * ind + 1, mid + 1, se, r);
    
}
int main()
{
    int n, m;
    cin >> n >> m;
    vi v(n + 1, 0);
    f(i, 1, n + 1) cin >> v[i];
    build(v, 1, 1, n);
    while (m-- > 0)
    {
        int r;
        cin >> r;
        if( r > table[1])cout<<0<<" ";
        else 
        {
            int k = findhotel( 1 ,1 , n , r ) ;
            cout<<k<<" ";
            update( 1 , 1 , n , k , v[k] - r  ) ;
            v[k] = v[k] - r ;
            // f( i , 1 , 2*n + 2 )cout<<table[i]<<" ";
            // cout<<endl;
        }
    }
    return 0;
}