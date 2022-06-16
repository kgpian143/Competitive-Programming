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
struct countarr
{
    int a ;
    int b ;
    int c ;
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int  q;
    cin>>q ;
    while(q-- > 0 )
    {
        int n ;
        cin>>n;
        string s ,  t ;
        cin>>s>>t ;
        countarr cnt1 , cnt2 ;
        cnt1.a = cnt1.b = cnt1.c = 0 ;
        cnt2.a = cnt2.b = cnt2.c = 0 ;
        bool ans = true ;
        for( int i = 0 ; i < n ; i++ )
        {
            if( s[i] == 'a')cnt1.a++ ;
            if( s[i] == 'b')cnt1.b++ ;
            if( s[i] == 'c')
            {
                cnt1.c++ ;
                if( cnt1.a > cnt2.a )
                {
                    ans = false ;
                    break;
                }
            }
            if( t[i] == 'a')cnt2.a++ ;
            if( t[i] == 'b')cnt2.b++ ;
            if( t[i] == 'c')
            {
                cnt2.c++ ;
                if( cnt2.a  != cnt1.a )
                {
                    ans = false ;
                    break;
                }
            }
            if(cnt1.a < cnt2.a )
            {
                ans = false ;
                break;
            }
            if( cnt2.c < cnt1.c )
            {
                ans = false ;
                break;
            }
        }
        if( cnt1.a != cnt2.a )ans = false ;
        if( cnt1.b != cnt2.b )ans = false ;
        if( cnt1.c != cnt2.c )ans = false ;
        if( ans )cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}