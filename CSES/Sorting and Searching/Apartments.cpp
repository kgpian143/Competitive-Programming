#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef map<long long, long long> mll;
typedef pair<int, int> pii;  
typedef pair<int, bool> pib;  
typedef pair<long long, long long> pll; 
typedef unsigned long long ull; 
typedef long double ld; 
typedef long long ll; 
typedef vector<vector<int>> vvi; 
typedef vector<pii> vpii; 
bool comp( int x , int y )
{
    return x > y ;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n , m , k ;
    cin>>n>>m>>k ;
    vi v( n , 0 );
    f(i,0,n)cin>>v[i] ;
    multiset<int> st ;
    f(i,0,m)
    {
        int a ;
        cin>>a ;
        st.insert(a) ;
    }
    sort(all(v) , comp ) ;
    // for( auto it : v )cout<<it<<" ";
    int cnt = 0 ;
    for( int i = 0 ; i < n ; i++)
    {
        if(st.size() == 0)break;
        // auto last = st.end() ;
        if( v[i] + k < *(st.begin()))continue;
        auto it  = st.upper_bound( v[i]) ;
        if( it == st.end())
        {
            if( *(--it) < v[i] - k )continue;
            else 
            {
                cnt++ ;
                st.erase(it) ;
                continue;
            }
        }
        if( *it <= v[i] + k )cnt++ ;
        else if( *(--it) >= v[i] - k )cnt++ ;
        else continue;
        st.erase(it);
    }
    cout<<cnt;
    return 0;
}