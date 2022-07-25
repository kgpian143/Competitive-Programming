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
int solution( vector<int> & v , int s  )
{
    int n =v.size() ;
    for( int i = 0 ; i < v.size() ; i++ )
    {
        v[i] -= s ; 
    }
    int cnt = 0, sum = 0;
    map<int, int> mp; 
    for (int i = 0; i < n; i++) {
        sum += v[i];
        if (sum == 0)
            cnt++;
        if (mp.find(sum) != mp.end())
            cnt += mp[sum];
        mp[sum]++;
    }
    if( cnt > 1e9 )cnt = 1e9 ;
    return cnt ;
}
void solve() 
{
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        solve();
    }
    return 0;
}