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

void solve() 
{
    int n , k ; 
    cin>>n>>k ;
    string s  ; 
    cin>>s ; 
    map<char , int> m ;
    for( int i = 0 ; i < s.size() ; i++ )
    {
        m[s[i]]++ ; 
    }
    // vector<int , char> vp ;
    int cnt1 = 0 , cnt2 = 0 ;
    for( auto it : m ) 
    {
        if( it.second & 1 ) 
        {
            cnt1++ ;
            cnt2 += it.second / 2  ;
        }
        else 
        {
            cnt2 += it.second/2  ;
        }
    }
    if( cnt2 < k ) 
    {
        cout<<1<<endl;
        return ;
    }
    else 
    {
        int ans = 2*(cnt2/ k) ; 
        int r = (cnt2 % k)*2 ; 
        if( cnt1 + r  >=  k )ans++ ;
        cout<<ans<<endl;
    }
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