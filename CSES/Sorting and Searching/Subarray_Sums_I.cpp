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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n , x;
    cin>>n >> x;
    vi v ;
    f(i,0,n)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int cnt = 0 , sum = 0 , i , j;
    for( i = 0 , j = 0 ; j < n ; j++ )
    {
        sum += v[j] ;
        while( sum > x  &&  i <= j ) 
        {
            sum -= v[i] ;
            i++ ;
        }
        if( sum == x )cnt++ ;
    } 
    for( ; i < n ; i++ )
    {
        sum = sum - v[i] ;
        if( sum == x)cnt++ ;
    }
    cout<<cnt<<endl;
    return 0;
}