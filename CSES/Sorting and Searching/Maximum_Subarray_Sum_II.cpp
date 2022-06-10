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
int n , a, b ;
vi v ;
struct segment
{
    int pref ;
    int suff ;
    int sum ;
    int maxseg ;
    int len ;
};
segment combine( segment s1 , segment s2 )
{
    segment ans ;
    ans.suff = max( s2.sum + s1.suff , s2.suff) ;
    ans.pref = max( s1.sum + s2.pref , s1.pref) ;
    ans.sum = s1.sum + s2.sum ;
    ans.maxseg = max( s1.maxseg , s2.maxseg ) ;
    ans.maxseg = max( ans.maxseg ,  s1.suff + s2.pref ) ;
    return ans ;
}
segment maxsum( int l , int r )
{
    if( l == r )
    {
        segment temp ;
        temp.pref = v[l] ;
        temp.suff = v[l] ;
        temp.sum = v[l] ;
        temp.maxseg = v[l] ;
        return temp ;
    }
    else 
    {
        int m = ( l + r) /2 ;
        return combine(maxsum(l , m ) , maxsum(m+1,r)) ;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    cin>>n>>a>>b ;
    for( int i = 0 ; i < n ; i++)
    {
        int a1 ;
        cin>> a1 ;
        v.push_back(a1);
    }
    cout<<maxsum(a,b).maxseg<<endl;
    return 0;
}