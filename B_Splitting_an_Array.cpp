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
int n , k  ;
vi v ;
bool good( int x ) 
{
    int sum = 0 ,  cnt = 0 ;
    for( int i = 0 ; i < n ; i++ )
    {
        if( v[i] > x) return false ;
        if( sum + v[i]  > x )
        {
            sum = v[i] ;
            cnt++ ;
        }
        else sum += v[i] ;
    }
    cnt++ ;
    // cout<<cnt<<endl;
    return cnt <= k ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    cin>>n>>k ;
    f(i,0,n)
    {
        int a ;
        cin>>a ;
        v.push_back(a) ;
    }
    int l = 0 ;
    int h = 1e15 ;
    while( h - l > 1 )
    {
        int m = ( h + l )/2 ;
        if( good(m) )h = m ;
        else l = m ;
        // cout<<l<<" "<<h<<endl ;
    }
    cout<<h ;
    return 0;
}