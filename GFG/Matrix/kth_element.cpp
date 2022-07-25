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

int solve(vvi v , int n  , int k ) 
{
    set<pair<int , pair<int , int >>> st ;
    st.insert({v[0][0] , { 0 , 0}}) ;
    vector<vector<bool>> ( n , vector<bool>(n ,false)) ;
    int cnt = 0 , num ;
    while( cnt < k )
    {
        auto it = (st.begin()) ;
        st.erase(it) ;
        cnt++ ;
        num = (*it).first ;
        pair<int ,int> b = (*it).second ;
        if(b.first + 1 < n )st.insert( { v[b.first + 1][b.second] , { b.first +1 , b.second }}) ;
        if(b.second + 1 < n )st.insert( { v[b.first][b.second + 1] , { b.first , b.second + 1 }}) ;
    }
    return num ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    { 
        int n , k ; 
        cin>>n>>k ;
        vvi v( n , vi(n)) ;
        f( i , 0 , n)
        {
            f( j , 0 , n)cin>>v[i][j] ;
        }
        // vvi  v ;
        cout<<solve(v , n , k)<<endl;
    }
    return 0;
}