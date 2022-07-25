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

void solve() 
{
    int a , b ,  c ; 
    cin>>a>>b>>c ; 
    if( ( a + c )/ ( (2.0) * b ) - ( a + c )/ ( 2 * b ) == 0  && ( a + c )/ ( (2.0) * b ) > 0 )cout<<"YES"<<endl;
    else if( ( 2*b - c )/ (  1.0 * a ) - (2 * b  - c )/ ( a ) == 0  && ( 2*b - c )/ (  1.0 * a )  > 0 )cout<<"YES"<<endl;
    else if( ( 2*b - a )/ (  1.0 * c ) - (2 * b  - a)/ ( c ) == 0  && (2*b - a )/ (  1.0 * c ) > 0 )cout<<"YES"<<endl;
    // else if( ( a + c )/ ( (2.0) * b ) - ( a + c )/ ( 2 * b ) == 0 )cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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