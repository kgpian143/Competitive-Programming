#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
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

class SegmentTree
{
    private:
      SegmentTree *left = NULL ;
      SegmentTree *right = NULL ;
      int st , end , mid ;
      bool isOut( int l , int r )
      {
          return ( r < st  || end < l ) ;
      }
      bool isIn( int l , int r )
      {
          return ( l <= st && end <= r );
      }
    //   void clear()
    //   {
    //       if( st == end )return  ;
    //       left->clear() ;
    //       right->clear() ;
    //       delete left ;
    //       delete right ;
    //       st = end = mid = 0 ;
    //   }
    long long int ans;

    public:
     SegmentTree( int st1 , int end1 )
     {
         st = st1 ;
         end = end1 ;
         mid = ( st + end )>>1 ;
     }                                                                                                                          
    void build( vector<int> &v)
    {
        // cout<<1;
        if( st == end )
        {
            ans = v[st] ;
            return ;
        }
        else 
        {
            // cout<<2 ;
            if( !left ) left = new SegmentTree( st , mid ) ;
            if( !right ) right = new SegmentTree(  mid + 1 , end) ;
            left->build(v);
            right->build(v) ;
            ans = (left->ans) + right->ans ;
        }
    }
    // int getValue( int pos )
    // {
    //     if( st == end )return ans ;
    //     if( mid >= pos )return left->getValue(pos) ;
    //     else return right->getValue(pos) ;
    // }
    void update( int i , int v )
    {
        if( st == end )
        {
            ans = v ;
            return ;
        }
        if( mid >= i )left->update( i , v );
        else right->update( i , v);
        ans = left->ans + right->ans ;
    }
    long long int getrangesum( int l , int r )
    {
        // if( st == end )return ans;
        if( isOut( l , r ))return 0 ;
        if( isIn( l , r ))return ans;
        return left->getrangesum(l,r) + right->getrangesum(l, r ) ;
    }
};

int main()
{
    int n ;
    cin>>n;
    vi v(2*n,0) ;
    vi a(2*n , 0 ) ;
    vi h( n + 1 , -1) ;
    f( i , 0 , 2*n )cin>>a[i] ;
    SegmentTree ST( 0 , 2*n - 1  ) ;
    ST.build(v);
    int q = 2*n ;
    mii m ;
    for( int i = 0 ; i < 2*n ; i++)
    {
        if( h[a[i]] == -1 )
        {
            h[a[i]] = i ;
        }
        else 
        {
            int sum = ST.getrangesum(h[a[i]] , i) ;
            ST.update(h[a[i]] , 1 );
            m[a[i]] = sum ;
        }
    }
    for( auto it : m )
    {
        cout<<it.second<<" ";
    }
    return 0 ;
}