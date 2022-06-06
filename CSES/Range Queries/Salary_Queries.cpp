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
// const int N = 1e9;
// long long int table[2 * N + 4] ;
const int N = 1e7 + 5 ;
int F[N] ;
// int salary[100*N] ;
// int table[2*N + 5] ;

void build( int ind  ,  int st , int se  )
{
      if (st == se) {
        table[ind] = F[st];
    } else {
        int tm = (st + se) / 2;
        build ( ind*2, st, tm);
        build(ind*2+1, tm+1, se);
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
        table[i] += new_val;
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
    int n , q ;
    cin>>n>>q ;
    vi v( n + 1 , 0 );
    int max_ = -1 ;
    for( int i = 1 ; i <= n ; i++ )
    {
        cin>>v[i] ;
        int k = (v[i] - 1)/100 ;
        F[k]++ ;
        salary[v[i]] ++ ;
        max_ = max(max_ , k ) ;
    }
    build( 1 , 0 , max_) ;
    while( q-- > 0 )
    {
        char ch ;
        cin>>ch ;
        if( ch == '?' )
        {
             int k , x  ;
             int k1 = (v[k]-1)/100 ;
             int k2 = (x-1)/100 ;
             update(1 , 1 , max_ , k1 ,  - 1 ) ;
            //  F[k1]-- ;
             update( 1 , 1 , max_ , k2 , 1 );
        }
        else 
        {
            int a , b ;
            cin>>a>>b ;
            int l = ( a - 1 )/100 ;
            int r = ( b - 1 )/100 ;
            int ans = sum( 1 ,  1 , max_ , l , r ) ;
            for( int i = 100*l ; i < a ; i++ )ans -= salary[i] ;
            for( int i = 100*r + 1 ; i <= b ; i++ )ans += salary[i] ;
            cout<<ans<<endl ;
        }
    }      
}
