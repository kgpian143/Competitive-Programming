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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n , x  ;
    cin>>n>>x ;
    multiset<int>  st ;
    for( int i = 0 ; i < n ; i++)
    {
        int a ;
        cin>>a ;
        st.insert(a) ;
    }
    int cnt = 0  ;
    while( st.size() > 0 )
    {
        // cout<<1 ;
        if(st.size() == 1 )
        {
            cnt++ ;
            st.erase(st.begin()) ;
            break;
        }
        int wt = *(st.begin()) ;
        st.erase(st.begin()) ;
        if( x - wt < *(st.begin()) )
        {
            cnt++ ;
            continue;
        }
        auto it = st.upper_bound(x-wt) ;
        st.erase(--it) ;
        cnt++ ;
    }
    cout<<cnt;
    return 0;
}