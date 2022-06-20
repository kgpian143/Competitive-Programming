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
const int N = 2e5 + 5; 

void solve() 
{
    int n ;
    cin>>n ;
    vi v( n , 0 ) ;
    getv(v , n ) ;
    int q ;
    int pref[n+1] ;
    pref[0] = 0 ; 
    f( i , 0 , n )pref[i+1] = pref[i] + v[i] ;
    int sum = accumulate( all(v) , 1LL*0) ;
    set<int> st ;
    f( i , 0 , n )
    {
        int a = pref[i+1]/(i+1) ;
        if( (1.0)*(pref[i+1]/(i+1)) != ((1.0) * pref[i+1])/(i+1))a++ ;
        st.insert(a) ;
    }
    int max_ele = *max_element( all(st)) ;
    // cout<<sum<<" "<<max_ele<<endl;
    cin>>q ;
    while( q-- > 0 )
    {
        int time ;
        cin>>time ;
        if( time  <  max_ele || n*time < sum )
        {
            cout<<-1<<endl;
            continue;
        }
        int num = sum/time ;
        if( (1.0)*(sum/time) != ((1.0) * sum)/time)num++ ;
        cout<<num<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t = 1;
    // cin>>t ;
    while(t-- > 0 )
    {
        solve();
    }
    return 0;
}