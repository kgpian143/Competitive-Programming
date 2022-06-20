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

void solve( int arr[] , int n ) 
{
    int ind = 0 ;
    for( int i = 1; i < n ; i++)
    {
        if( arr[i] >= arr[ind] )ind = i ;
    }
    int pref[n+1] ;
    pref[0] = 0 ;
    for( int i = 0 ; i < n ;i++)pref[i+1] = pref[i] + arr[i] ;
    int min_ind = 0 ;
    int sum = 0 ;
    for( int i = 1 ; i <= ind ; i++ )
    {
        if( arr[i] >= arr[min_ind] )
        {
            sum += arr[min_ind]*( i - min_ind) - pref[i] + pref[min_ind];
            min_ind = i ;
        }
    }
    min_ind = n-1 ;
    // cout<<sum<<" ";
    for( int j = n-2 ; j >= ind ; j-- )
    { 
        if( arr[j] > arr[min_ind] )
        {
            sum += arr[min_ind]*( min_ind - j ) + pref[j+1] - pref[min_ind+1];
            min_ind = j ;
        } 
    }
    cout<<sum<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n ;
        cin>>n;
        int arr[n+1] ;
        f( i , 0 , n )cin>>arr[i] ;
        solve( arr , n);
    }
    return 0;
}