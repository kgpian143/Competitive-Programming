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
unordered_set < string > st ;
void permute( string s , int l , int r ) 
{
     if( l == r )st.insert(s) ;
     else 
     {
        for( int i = l ; i <= r ; i++ )
        {
            swap(s[i] , s[l]);
            permute( s  , l + 1 , r ) ;
            swap( s[i] , s[l]) ;
        }
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
        int n ;
        cin>>n ;
        string s ;
        cin>>s ;
        permute(  s  , 0 , n-1);
        for( auto it : st )
        {
            cout<<it<<endl;
        }
        cout<<st.size()<<endl;
        st.clear() ;
    }
    return 0;
}