#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
const int N = 2e5 + 5 ;
int bit[N] ;
class FenwickTree
{
    private:
     int size ;
    public:
    FenwickTree( vector<int> v )
    {
        int size = v.size() - 1 ;
        int n = v.size() - 1 ;
        for( int i = n ; i > 0 ; i-- )
        {
            for( int j = i - ( i & -i) + 1 ; j <= i ; j++ )bit[i] += v[i] ;
        }
    }
    int sum( int i )
    {
        int ans = 0 ;
        for( ; i > 0 ; i -= ( i & -i))
        {
            ans += bit[i] ;
        }
    }
    int update( int k , int x  )
    {
        for( int i = k ; i <= size ; i = i + ( i & -i) )bit[i] = bit[i] + x ;
    }
};

int main()
{

    return 0;
}