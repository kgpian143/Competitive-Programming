#include<bits/stdc++.h>
using namespace std ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mod 1000000007 
#define int long long 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
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
const int N = 2e5 + 5; 

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n ;
    cin>>n ;
    vpii vp ,  v ;
    map<pii , int> v1 ,  v2 ;
    for( int i = 0 ; i < n ; i++ )
    {
        int a , b ;
        cin>>a>>b ;
        v.push_back({a , -b}) ;
        vp.push_back({a , -b}) ;
    } 
    sort(all(v)) ;
    int maxr = 0 ;
    for( int i = 0 ; i < n ; i++)
    {
        if( maxr >= -(v[i].second))v1[v[i]] = 1 ;
        else 
        {
            maxr = -v[i].second ;
        }
    }
    int minr = INT_MAX ;
    for( int i = n-1 ; i >= 0 ; i--)
    {
        if( minr <= -(v[i].second))v2[v[i]] = 1 ;
        else 
        {
            minr = -v[i].second ;
        }
    }
    for( int i = 0 ; i < n ; i++)cout<<v2[vp[i]]<<" ";
    cout<<endl;
    for( int i = 0 ; i < n ; i++)cout<<v1[vp[i]]<<" ";
    return 0;
}