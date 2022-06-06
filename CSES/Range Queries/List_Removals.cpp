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
int table[4*N];
vi present(N, 1);
void build( int ind ,  int st , int se )
{
    if (st == se)
    {
        table[ind] = present[st];
    }
    else
    {
        int tm = (st + se) / 2;
        build(ind * 2, st, tm);
        build( ind * 2 + 1, tm + 1, se);
        table[ind] = table[ind * 2] + table[ind * 2 + 1];
    }
}
int sum(int v, int st, int se, int l, int r)
{
    if (l > r)
        return 0;
    if (l == st && r == se)
    {
        return table[v];
    }
    int tm = (st + se) / 2;
    return sum(v * 2, st, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, se, max(l, tm + 1), r);
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
        table[i] = table[i * 2] + table[i * 2 + 1];
    }
}
int findpos(int ind, int st, int se, int sm)
{
    if( st == se )return se ;
    int mid = (st + se) / 2;
    if (table[2 * ind] > sm)
        return findpos(2 * ind, st, mid, sm);
    else if (table[2 * ind] < sm)
        return findpos(2 * ind + 1, mid + 1, se, sm - table[2 * ind]);
    else
    {
        if (present[mid] == 1)
            return mid;
        else
            return findpos(2 * ind, st, mid, sm);
    }
}
int main()
{
    int n ;
    cin >> n ;
    vi v(n + 1, 0);
    f(i, 0, n) cin >> v[i + 1];
    // vi present(n + 1, 1);
    // cout<<"dv";
    build(1 , 1, n);
    int k = n ;
    // cin>>k ;
    while (k-- > 0)
    {
        int pos;
        cin >> pos;
        // cout<<"kl\n";
        if (sum(1, 1, n, 1, pos) == pos && present[pos] == 1)
        {
            cout << v[pos] << " ";
            update( 1 , 1 , n , pos , 0 );
            present[pos] = 0 ;
        }
        else
        {
            // cout<<1;
            int b = findpos(1, 1, n, pos);
            // cout<<"pos"<<b<<endl ;
            cout << v[b] << " ";
            present[b] = 0;
            update(1, 1, n , b, 0);
        }
    }
    return 0;
}