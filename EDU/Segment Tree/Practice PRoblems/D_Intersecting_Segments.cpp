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
          return ( st > r || end < l ) ;
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
            ans = max(left->ans , right->ans) ;
        }
    }
    int getValue( int x , int l )
    {
        if( st == end )
        {
            if( st < l )return -1 ;
            if( ans < x )return -1 ;
            else return st ;
        }
        if( end < l )return -1 ;
        int k1 , k2 ;
        // if( left->ans >= x  )return left->getValue(x , l ) ;
        // else if( right->ans >= x )return right->getValue(x , l) ;
        k1 = left->getValue(x , l ) ;
        // k2 = right->getValue(x , l) ;
        if( k1 == -1 )
        {
            return  right->getValue(x , l);
        }
        else return k1 ;
        // else return -1;
    }
    void update( int i , int v )
    {
        if( st == end )
        {
            ans = v ;
            return ;
        }
        if( mid >= i )left->update( i , v );
        else right->update( i , v);
        ans = max(left->ans , right->ans );
    }
    long long int getrangemax( int l , int r )
    {
        // if( st == end )return ans;
        if( isOut( l , r ))return INT_MIN ;
        if( isIn( l , r ))return ans;
        return max(left->getrangemax(l,r) , right->getrangemax(l , r)) ;
    }
};

int main()
{
    int n ,  q ;
    cin>>n>>q ;
    vi v(n,0) ;
    f( i , 0 , n )cin>>v[i] ;
    SegmentTree ST( 0 , n - 1 ) ;
    ST.build(v);
    while( q-- > 0 )
    {
        int t ;
        cin>>t ;
        if( t == 1 )
        {
            int i , v ;
            cin>>i>>v ;
            ST.update( i , v );
        }
        else 
        {
            int x , l;
            cin>>x >> l;
            cout<<ST.getValue(x , l)<<endl;
        }
    }
    return 0 ;
}