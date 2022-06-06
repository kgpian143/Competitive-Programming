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

struct segment 
{
    long long int maxim ;
    long long int add ;
};
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
      segment ans;

    public:
     SegmentTree( int st1 , int end1 )
     {
         st = st1 ;
         end = end1 ;
         mid = ( st + end )>>1 ;
     }                                                                                                                          
    void build( vector<int> &v)
    {
        if( st == end )
        {
            ans.maxim = v[st] ;
            ans.add = 0;
            return ;
        }
        else 
        {
            if( !left ) left = new SegmentTree( st , mid ) ;
            if( !right ) right = new SegmentTree(  mid + 1 , end) ;
            left->build(v);
            right->build(v) ;
            ans.maxim = max(left->ans.maxim , right->ans.maxim) ;
            ans.add = 0;
        }
    }
    void propagate()
    {
        if( st == end)
        {
            ans.maxim +=  ans.add ;
            ans.add = 0 ;
            return ;
        }
        else 
        {
            ans.maxim += ans.add ;
            left->ans.add += ans.add ;
            right->ans.add += ans.add ;
            ans.add = 0 ;
        }
    }
    int getValue( int x , int l )
    {
        if(ans.add != 0 )propagate();
        if( st == end )
        {
            if( ans.maxim < x )return -1 ;
            if( st < l )return -1 ;
            return st ;
        }
        if( end < l )return -1 ;
        int k1 ;
        k1 = left->getValue(x , l ) ;
        if( k1 == -1 )
        {
            return  right->getValue(x , l);
        }
        else return k1 ;
        // if( mid > l && right->ans.maxim >= x)return left->getValue(x,l ) ;
        // else if( l <= mid && left->ans.maxim >= x  )
        // {
        //     int k1 = left->getValue(x,l) ;
        //     if( k1 == -1)
        //     {
        //         if( right->ans.maxim >= x )return right->getValue(x,l) ;
        //         else return -1 ;
        //     }
        //     else return k1 ;
        // }
        // else return -1 ;
    }
    void update(int val, int l, int r)
    {
        if(ans.add != 0 )propagate() ;  
        if (isOut(l, r))
            return;
        if (isIn(l, r))
        {
            ans.add += val ;
            return ;
        }
        else
        {
            left->update(val, l, r);
            right->update(val, l, r);
            ans.maxim = max( left->ans.maxim   , right->ans.maxim  ) ;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n ,  q ;
    cin>>n>>q ;
    vi v(n,0) ;
    // f( i , 0 , n )cin>>v[i] ;
    SegmentTree ST( 0 , n - 1 ) ;
    ST.build(v);
    while( q-- > 0 )
    {
        int t ;
        cin>>t ;
        if( t == 1 )
        {
            int l , r  , v ;
            cin>>l>>r>>v ;
            ST.update( v  , l , r-1);
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