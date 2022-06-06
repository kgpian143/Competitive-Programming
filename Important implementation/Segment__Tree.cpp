#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
const int N = 2e5 + 5 ;
int table[4*N] ;

void build( vector<int>& v , int ind  ,  int st , int se  )
{
      if (st == se) {
        table[ind] = v[st];
    } else {
        int tm = (st + se) / 2;
        build(v, ind*2, st, tm);
        build(v, ind*2+1, tm+1, se);
        table[ind] = table[ind*2] + table[ind*2+1];
    }
}
int sum(int v, int st, int se, int l, int r) {
    if (l > r) 
        return 0;
    if (l == st && r == se) {
        return table[v];
    }
    int tm = (st + se) / 2;
    return sum(v*2, st, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, se, max(l, tm+1), r);
}


void update(int i, int st, int se , int pos, int new_val) {
    if (st == se ) {
        table[i] = new_val;
    } else {
        int tm = (st + se ) / 2;
        if (pos <= tm)
            update(i*2, st, tm, pos, new_val);
        else
            update(i*2+1, tm+1, se , pos, new_val);
        table[i] = table[i*2] + table[i*2+1];
    }
}


int main()
{
    
    return 0;
}