#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
const int N = 2e5 + 5 ;
long long int table[4*N] ; 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
typedef vector<int> vi; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef map<long long, long long> mll;
typedef pair<int, int> pii;  
typedef pair<long long, long long> pll; 
typedef unsigned long long ull; 
typedef long double ld; 
typedef long long ll; 
typedef vector<vector<int>> vvi; 
typedef vector<pii> vpii; 

void build( vector<int> &v , int ind , int st , int se   )
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
long long int sum(  int v , int st, int se, int l, int r ) {
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
    int n , q ;
    cin>>n>>q ;
    vi v( n+1 , 0 ) ;
    f( i , 1 , n + 1)cin>>v[i] ;
    // cout<<1;
    build( v , 1 , 1 , n ) ;
    // cout<<1;
    while( q-- > 0 )
    {
        int t , a , b ;
        cin>>t>>a>>b ;
        if( t == 1 )
        {
            update( 1 , 1 , n , a , b ) ;
        }
        else 
        {
            cout<<sum(  1 , 1 , n , a , b ) << endl ;
        }
    }
    return 0;
}