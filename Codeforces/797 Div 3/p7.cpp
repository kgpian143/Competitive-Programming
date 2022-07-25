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
    int n , m ; 
    cin>>n>>m ; 
    vi v( n , 0 ) ; 
    f( i , 0 , n )cin>>v[i] ; 
    set<int> st ; 
    f( i , 0 , n ) 
    {
        if( st.empty() || v[i] < v[*(st.rbegin())]) st.insert(i) ;
    }
    for( int i = 0 ; i < m ; i++) 
    {
        int k , d  ;
        cin>>k>>d ;
        k-- ; 
        v[k] = v[k] - d  ;  
        auto it = st.upper_bound(k) ; 
        if( it != st.begin())
        {
            it = prev(it) ; 
            if( *it == k || v[k] < v[*it])st.insert(k) ;
        }
        // else 
        // {
        //     st.insert(k) ; 
        // }
        while(1)
        {
            auto it = st.upper_bound(k) ;
            if( it == st.end())break ;
            if( v[*it] >= v[k])st.erase(it) ;
            else break; 
        }
        cout<<st.size()<<" ";
    }
    cout<<endl;
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