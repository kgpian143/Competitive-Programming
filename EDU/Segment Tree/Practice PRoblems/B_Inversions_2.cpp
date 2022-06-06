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
// queue<SegmentTree> q ;
class SegmentTree
{
    private:
      SegmentTree *left = NULL ;
      SegmentTree *right = NULL ;
      
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
     int st , end , mid ;
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
    int getValue( int k )
    {
        if( st == end )return st ;
        // if( k == ans && v[end] == 1 )return end ;
        else if(  k > right->ans ) return left->getValue( k - right->ans ) ;  
        else return right->getValue(k) ;
    }
    void update( int i  )
    {
        if( st == end )
        {
            ans = (ans ^ 1) ;
            return ;
        }
        if( mid >= i )left->update( i );
        else right->update( i );
        ans = left->ans + right->ans ;
    }
    long long int getrangesum( int l , int r )
    {
        // if( st == end )return ans;
        if( isOut( l , r ))return 0 ;
        if( isIn( l , r ))return ans;
        return left->getrangesum(l,r) + right->getrangesum(l, r ) ;
    }
    //  void print( )
    // {
    //     // queue<SegmentTree> q ;
        
    // }
};
//

int main()
{
    int n , m ;
    cin>>n ;
    vi  v( n+1 , 1 );
    // f(i,0,n)cin>>v[i] ;
    SegmentTree ST( 1 , n );
    ST.build(v) ;
    m = n ;
    vi inp( n+1 , 0 );
    vi outp ;
    f( i , 0  , n )cin>>inp[i] ;
    while( m-- > 0 )
    {
        int p ;
        p = inp[m] ;
        int k = ST.getValue(p+1) ;
        // cout<<k<<" ";
        outp.push_back(k) ;
        ST.update(k);
    }
    for( int i = n -1 ; i >= 0 ; i--)cout<<outp[i]<<" ";
}