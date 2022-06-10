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
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n ;
        cin>>n ;
        vi  s(n) , fin(n) ;
        f(i,0,n)cin>>s[i];
        f(i,0,n)cin>>fin[i];
        vi  ans ;
        ans.push_back( fin[0] - s[0]) ;
        int k = fin[0] ;
        for( int i = 1 ; i < n ;i++ )
        {
            int a = fin[i] - max( s[i] , k ) ;
            ans.push_back(a) ;
            k = fin[i] ;
        }
        for(auto it : ans)cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}