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
    cin>> n ;
    vi v(n,0) ;
    multiset<int> st ;
    f(i,0,n)
    {
        cin>>v[i] ;
        st.insert(v[i]) ;
    }
    sort(all(v)) ;
    int k = 0 ;
    for( int i = 0 ; i < n ; i++ )
    {
        if(v[i] > k + 1 )break ;
        else 
        {
            k += v[i] ;
        }
    }
    cout<<k+1 ;
    return 0;
}