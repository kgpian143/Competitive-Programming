#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
const int N = 2e5 + 5;
int table[4*N];

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
    }
}
// void propagate( )
int find(int pos, int ind, int st, int se)
{
    if (st == se)
        return table[ind];
    if (table[ind] != 0)
    {
        int left = 2 * ind;
        int right = 2 * ind + 1;
        table[left] += table[ind];
        table[right] += table[ind];
        table[ind] = 0;
    }
    int mid = (st + se) / 2;
    if (pos >= st && pos <= mid)
    {
        return find(pos, 2 * ind, st, mid);
    }
    else
        return find(pos, 2 * ind + 1, mid + 1, se);
}

void update(int val, int ind, int st, int se, int l, int r)
{
    if (l > se || r < st)
        return;
    if (l <= st && r >= se)
    {
        table[ind] += val;
        return;
    }
    else if (st == se)
        table[ind] += val;
    else
    {
        int mid = (st + se) / 2;
        update(val, 2 * ind, st, mid, l, r);
        update(val, 2 * ind + 1, mid + 1, se, l, r);
    }
}

int main()
{

    return 0;
}