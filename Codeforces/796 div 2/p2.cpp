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
const int N = 2e5 + 5 ;
int num[N] ;
int pow2( int x )
{
    int k = 0 ;
    while( x % 2 == 0 )
    {
        x = x/2 ;
        k++ ;
    }
    return k ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n ;
        cin>>n ;
        vi v(n , 0 );
        int cnt1 = 0 , cnt2 = 0  , min_pow = INT_MAX;
        f(i,0,n)
        {
            cin>>v[i] ;
            if( v[i] % 2 == 1 )cnt1++ ;
            else 
            {
                cnt2++ ;
                min_pow = min(min_pow , pow2( v[i])) ;
            }
        }
        if( cnt1 > 0 )cout<<cnt2<<endl ; 
        else 
        {
            cout<< min_pow + cnt2 - 1 << endl;
        }
    }
    return 0;
}