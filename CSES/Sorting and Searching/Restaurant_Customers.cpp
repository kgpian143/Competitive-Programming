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
    int n ;
    cin>>n ;
    vpii v ;
    f(i,0,n)
    {
        int a , b ;
        cin>>a>>b ;
        v.push_back({a , b}) ;
    }
    sort(all(v));
    multiset<int> st ;
    st.insert(v[0].second) ;
    int ans = 1  ;
    for( int i = 1 ; i < n ;i++)
    {
        while( *(st.begin()) <= v[i].first && st.size() > 0 )st.erase(st.begin()) ;
        st.insert(v[i].second) ;
        ans = max( ans ,  (int)st.size()) ;
    }
    cout<<ans ;
    return 0;
}