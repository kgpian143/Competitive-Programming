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
long long int lazy[4 * N];
void buildtable(vector<int> &v, int ind, int st, int end)
{
    if (st == end)
    {
        table[ind] = v[st];
        return ;
    }
    int mid = (st + end) / 2;
    buildtable(v, 2 * ind, st, mid);
    buildtable(v, 2 * ind + 1, mid + 1, end);
    table[ind] = table[2 * ind] + table[2 * ind + 1];
}

// void buildlazy( )
void propagate(int ind, int st, int end)
{
    if (st == end)
    {
        table[ind] += lazy[ind];
        lazy[ind] = 0;
    }
    else
    {
        table[ind] += ( end - st + 1)*lazy[ind] ; 
        lazy[2 * ind] += lazy[ind];
        lazy[2 * ind + 1] += lazy[ind];
        lazy[ind] = 0;
    }
}
void update( int ind  , int st , int end , int l , int r , int val )
{
    propagate( ind , st , end) ;
    // cout<<2;
    if( r < st || l > end )return ;
    else if( st == end )
    {
        table[ind] += val ;
        // cout<<3;
        return ;
    }
    else if( l <= st && end <= r )
    {
        lazy[ind] += val ;
        propagate( ind  , st , end ) ;
        // cout<<4 ;
        return ;
    }
    else 
    {
        // cout<<5;
        int mid = ( st + end)/2 ;
        update( 2* ind , st , mid , l , r , val );
        update( 2* ind + 1 , mid + 1 , end , l , r , val );
        table[ind] = table[2*ind] + table[2*ind + 1 ] ;
        
    }
}
long long int suminrange( int ind , int st , int end , int l , int r )
{
   if( r < st || l > end )return 0;
   if( st == end )
   {
       return table[ind] ;
   }
   else if( l <= st && end <= r )
   {
       return table[ind] ;
   }
   else 
   {
       int mid = ( st + end) /2 ;
       return (suminrange( 2 * ind  , st , mid , l , r  ) + suminrange( 2*ind + 1 , mid + 1 , end , l , r ));
   }
}
int main()
{
    int n ;
    cin>>n ;
    vi v( n + 1 , 0 ) ;
    f( i , 0 , n )cin>>v[i+1] ;
    buildtable( v , 1 , 1 , n) ;
    // cout<<1 ;
    int q ;
    cin>>q ;
    while( q-- > 0 )
    {
        int t ;
        cin>>t ;
        if( t == 0 )
        {
            int l , r ;
            cin>>l>>r ;
            cout<<suminrange( 1 , 1 , n ,  l , r )<<endl;
        }
        else 
        {
            int l , r , val ;
            cin>>l>>r>>val ;
            update( 1 , 1 , n , l , r , val );
        }
    }
    return 0;
}