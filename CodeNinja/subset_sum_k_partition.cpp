#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define int  long long  
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<int> vl;
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii;
typedef map<int, int> mll;
typedef pair<int, int> pii;  
typedef pair<int, bool> pib; 
typedef pair<int, int> pll; 
typedef unsigned int ull; 
typedef long double ld; 
typedef int ll; 
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;
const int N = 1e5 + 5 ;

bool recursion( vector<int> &v , int mask , int k , int partition_sum )
{

    vector<int> curr_num ; 
    int l = v.size() ;
    for( int i = 0 ; i < l ; i++ )
    {
        if( ( mask & ( 1 << i )) )continue;
        curr_num.push_back(v[i]) ;
    }
    int sm = accumulate( curr_num.begin(), curr_num.end() , 0 ) ;
    cout << sm << endl ;
    int n = curr_num.size() ;
    if( k == 1 )
    {
        if( sm == partition_sum) return true ;
        return false ;
    }
    bool ans = false ;
    for( int i = 0 ; i < (1 << n) ; i++)
    {
        int sum = 0 ; 
        for( int j = 0 ; j < n ; j++ )
        {
            if( i  & ( 1 << j ))sum += v[j] ; 
        }
        if( sum == ( partition_sum) )
        {
            cout << sum << " " << k  << endl ;
            // if( k  == 2 )return true ;
            ans |= recursion( curr_num , i , k - 1 , partition_sum ) ;
        }
        if( ans )break;
    }
    if( ans ) return true ;
    return false ;
} 
void solve()
{
    int n , k ; 
    cin >> n ;
    vi v( n , 0 ) ;
    for( auto &it : v )cin >> it ;
    cin >> k ;
    
    int sum = accumulate( v.begin() , v.end() , 0 ) ;
    // cout << sum << endl ;
    if((sum % k) != 0 )
    {
        cout << "False\n" ;
        return ;
    }
    bool ans = recursion( v , 0 , k  , sum / k ) ;

    ans ? cout << "True\n" : cout << "False\n" ; 
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ; 
    cin>>t ; 
    while(t-- > 0 )
    {
        solve() ;
    }
    return 0;
}