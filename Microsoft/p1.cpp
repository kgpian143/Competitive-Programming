#include<bits/stdc++.h>
using namespace std ;

// #define int long long 
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
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
const int N = 2e5 + 5; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<long long,int>, null_type,less<pair<long long,int>>, rb_tree_tag,tree_order_statistics_node_update>

ordered_set st;

int solution( vector<int> & v , int s  )
{
    st.clear();
    int n = v.size();
    vector<long long> a(v.begin(),v.end());
    for(int i=0;i<n;i++) a[i] -= s;

    vector<long long> pref(n);
    partial_sum(a.begin(),a.end(),pref.begin());

    for(int i=0;i<n;i++)
    {
        st.insert(make_pair(pref[i],i));
    }
    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        long long reqd  = 0;
        if(i != 0) reqd = pref[i-1];
        ans += st.size() - st.order_of_key(make_pair(reqd+1,-1));
        st.erase(make_pair(pref[i],i));
    }

    if(ans > 1000000000) ans = 1000000000;
    return ans;
}
void solve() 
{
    int n , s ; 
    cin>>n >> s ; 
    vi v ( n , 0 ) ; 
    f( i , 0 , n )cin>>v[0] ; 
    cout<<solution( v , s ) <<endl ;
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