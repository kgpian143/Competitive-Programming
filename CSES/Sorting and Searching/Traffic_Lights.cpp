#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define int long long 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
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
const int N = 2e5 + 5; 

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n , x;
    cin>>x >> n ;
    multiset<int> dist ;
    set<int> st ;
    st.insert(0) ;
    st.insert(x) ;
    dist.insert(x) ;
    for( int i = 0 ; i < n ; i++ )
    {
        int a ;
        cin>>a ;
        auto it = st.upper_bound(a) ;
        int d1 = *it ;
        int d2 = *(--it) ;
        dist.erase(dist.find(d1-d2)) ;
        dist.insert( d1 - a );
        dist.insert( a - d2) ;
        st.insert(a) ;
        cout<<*(--dist.end())<<" ";
    }
    return 0;
}