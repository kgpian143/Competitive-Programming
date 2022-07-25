#include<bits/stdc++.h>
using namespace std ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long 
typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef pair<int, int> pii;  
typedef pair<int, bool> pib;  
typedef unsigned long long ull; 
typedef long double ld; 
typedef vector<pii> vpii; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
#define getv(v,n) for( int i = 0 ; i < n ; i++)cin>>v[i];
#define putv(v) for(auto it : v )cout<<it<<' ';
#define getvv(v,n,m)for(int i = 0 ; i < n ; i++ )f(j,0 ,m)cin>>v[i][j] 
const int N = 2e5 + 5; 

float MO2(int a, int b)
{ return ( a + b ) / 2.0; }
  
// A utility function to find median of three integers
float MO3(int a, int b, int c)
{
    return a + b + c - max(a, max(b, c))
                     - min(a, min(b, c));
}
  
// A utility function to find a median of four integers
float MO4(int a, int b, int c, int d)
{
    int Max = max( a, max( b, max( c, d ) ) );
    int Min = min( a, min( b, min( c, d ) ) );
    return ( a + b + c + d - Max - Min ) / 2.0;
}
  
// Utility function to find median of single array
float medianSingle(int arr[], int n)
{
   if (n == 0)
      return -1;
   if (n%2 == 0)
        return (double)(arr[n/2] + arr[n/2-1])/2;
   return arr[n/2];
}
float findMedianUtil( int A[], int N, int B[], int M )
{
    // If smaller array is empty, return median from second array
    if (N == 0)
      return medianSingle(B, M);
    if (N == 1)
    {
        if (M == 1)
            return MO2(A[0], B[0]);
  
        if (M & 1)
            return MO2( B[M/2], MO3(A[0], B[M/2 - 1], B[M/2 + 1]) );
 
        return MO3( B[M/2], B[M/2 - 1], A[0] );
    }
  
    // If the smaller array has two elements
    else if (N == 2)
    {
        // Case 4: If the larger array also has two elements,
        // simply call MO4()
        if (M == 2)
            return MO4(A[0], A[1], B[0], B[1]);
        if (M & 1)
            return MO3 ( B[M/2],max(A[0], B[M/2 - 1]), min(A[1], B[M/2 + 1]));
        return MO4 ( B[M/2], B[M/2 - 1], max( A[0], B[M/2 - 2] ),min( A[1], B[M/2 + 1] ) );
    }
  
    int idxA = ( N - 1 ) / 2;
    int idxB = ( M - 1 ) / 2;
  
     /* if A[idxA] <= B[idxB], then median must exist in
        A[idxA....] and B[....idxB] */
    if (A[idxA] <= B[idxB] )
      return findMedianUtil(A + idxA, N/2 + 1, B, M - idxA );
  
    /* if A[idxA] > B[idxB], then median must exist in
       A[...idxA] and B[idxB....] */
    return findMedianUtil(A, N/2 + 1, B + idxA, M - idxA );
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n , m ; 
        cin>>n>>m ;
        int arr1[n] , arr2[m] ;
        f(i , 0 ,  n)cin>>arr1[i] ;
        f(i , 0 ,  m)cin>>arr2[i] ;
        if( n > m )cout<<findMedianUtil( arr2 , m , arr1 , n )<<endl;
        else cout<<findMedianUtil( arr1 , n ,  arr2 , m )<<endl;

    }
    return 0;
}