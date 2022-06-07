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
int pos[N] ;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n ;
    cin>>n ;
    vpii v ;
    f(i,0,n)
    {
        int a;
        cin>>a;
        v.push_back({a , i+1});
    }
    stack<pii> st ;
    for( int i = 0 ; i < n ; i++ )
    {
        // if( st.empty())pos[i] = 0 ;
        while(!(st.empty()) && st.top().first >= v[i].first )st.pop() ;
        if( st.empty())
        {
            pos[i] = 0 ;
            st.push(v[i]) ;
        }
        else 
        {
            pos[i] = st.top().second ;
            st.push(v[i]) ;
        }
    }
    for( int i = 0 ; i < n ;i++)cout<<pos[i]<<" ";
    return 0;
}