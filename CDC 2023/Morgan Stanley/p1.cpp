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

string solve()
{
    int n ;
    cin >> n ;
    vector<string> s( n , "") ;
    for( int i = 0 ; i < n ; i++ )cin >> s[i] ; 
    vector<string> arr;
    int len = 27 ;

    for( int i = 0 ; i < n ; i++)
    {
        string str ;
        for( int j = 1 ; j < s[i].size() ; j++)  
        {
            str.push_back(s[i][j] - s[i][j-1] + '0') ;
        }
        int k = str.size() ;
        len = min( len , k ) ;
        arr.push_back(str) ; 
    }
    int ind = -1 ;
    map<string ,int >  mp ;
    string s1 = arr[0].substr( 0 , len ) ;
    for( int i = 1 ; i < arr.size(); i++)
    {
        string s2 = arr[i].substr( 0 , len) ;
        if( i == 1 )
        {
            if( s2 != s1 )
            {
                string s3 = arr[i+1].substr( 0 , len) ;
                if( s3 == s2 )return s[0] ;
                else return s[1] ;
            }
        }
        else 
        {
            if( s2 != s1 )return s[i] ;
        }
    }  
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ; 
    cin>>t ; 
    while(t-- > 0 )
    {
       cout << solve() ;
    }
    return 0;
}