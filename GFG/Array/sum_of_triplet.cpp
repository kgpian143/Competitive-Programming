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
const int N = 2e5 + 5; 

bool find3Numbers(int A[], int n, int X)
{
    //Your Code Here
    sort( A , A+n );
    for( int i = 0 ; i < n ; i++)
    {
        int x2 = X - A[i] ;
        for( int k = i+1 , j = n-1; k < j ; k++ )
        {
            while(A[k] + A[j] > x2 )j-- ;
            if( k < j && A[i] + A[j] + A[k] == X )return true ;
        }
    }
    return false ;
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n , x  ;
        cin>>n>>x ;
        int arr[n] ;
        f( i , 0 , n )cin>>arr[i] ;
        cout<<find3Numbers(arr , n , x) <<endl;
    }
    return 0;
}