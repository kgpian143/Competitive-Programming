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
const int N = 2e5 + 5 ;
long long int bit[N] ;
class FenwickTree
{
    public:
     int size ;
    // FenwickTree( vector<int> v )
    // {
    //     int size = v.size() - 1 ;
    //     int n = v.size() - 1 ;
    //     for( int i = n ; i > 0 ; i-- )
    //     {
    //         for( int j = i - ( i & -i) + 1 ; j <= i ; j++ )bit[i] += v[j]*1LL ;
    //     }
    // }
    long long int sum( int i )
    {
        long long int ans = 0 ;
        for( ; i > 0 ; i -= ( i & -i))
        {
            ans += bit[i] ;
        }
        return ans ;
    }
    void update( int k , int x  )
    {
        for( int i = k ; i <= size ; i = i + ( i & -i) )bit[i] = bit[i] + x ;
    }
};

int main()
{
    int n , q ;
    cin>>n>>q ;
    vi v( n+1 , 0 ) ;
    f( i , 1 , n + 1)cin>>v[i] ;
    FenwickTree ft ;
    ft.size = n ;
    for( int i = 1 ; i <= n ; i++)ft.update( i ,  v[i]) ;
    // f( i  , 0 ,  n+1)cout<<bit[i]<<" ";
    // cout<<endl;
    
    while(q-- > 0 )
    {
       int t , a , b ;
       cin>>t>>a>>b ;
       if( t == 1 )
       {
           ft.update(a , b - v[a]) ;
           v[a] = b ;
       }
       else 
       cout<<ft.sum( b ) - ft.sum(a-1) <<endl ;
    }
    return 0;
}