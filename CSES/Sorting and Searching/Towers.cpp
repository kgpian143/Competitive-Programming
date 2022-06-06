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
    int n ;
    cin>>n ;
    vi v( n , 0 ) ;
    f( i , 0 , n )cin>>v[i] ;
    multiset<int> st ;
    for( int i = 0 ; i < n ; i++ )
    {
        auto it = st.upper_bound(v[i]) ;
        if( it == st.end())
        {
            st.insert(v[i]) ;
        }
        else 
        {
            st.erase(it) ;
            st.insert(v[i]) ;
        }
    }
    cout<<st.size();
    return 0;
}