#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define int  long long  
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define pb push_back 
#define mp make_pair 
#define ff first 
#define ss second 
#define endl '\n' 
#define sp ' ' 
#define all(v) v.begin() , v.end() 
#define rall(v) v.rbegin() , v.rend() 
#define yes cout << "YES" << endl ;
#define no cout << "NO" << endl ;
#define debg(x) cout << "x : " << x << endl 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii;
typedef map<int, int> mll;
typedef pair<int, int> pii;  
typedef pair<int, bool> pib; 
typedef unsigned int ull; 
typedef long double ld; 
typedef vector<pii> vpii;
typedef vector<pib> vpib;
const int N = 1e5 + 5 ;

void solve( vector<string> commands )
{
    vector<int> ans ;
    int n =  commands.size() ;
    map<string , int> m ;
    for( int i = 0 ; i < n ; i++ )
    {
        if( i == 0 )
        {
            for( int j = 1 ; j < commands[i].size() ; j++ )
            {
                m[commands[i].substr( 0 , j)] = i + 1 ; 
            }
            ans.push_back(0) ;
        }
        else{
            for( int j = commands[i].size() ; j > 0 ; j--)
            {
                if( ans.size() == i+1 )
                {
                    m[commands[i].substr( 0 , j )] = i + 1;
                }
                else if( m[commands[i].substr( 0 , j)]){
                     ans.push_back( m[commands[i].substr( 0 , j )]) ;
                     m[commands[i].substr( 0 , j )] = i ;
                }
                else 
                {
                    m[commands[i].substr( 0 , j )] = i + 1 ;
                }
            }
        }
        if( ans.size() == i )ans.push_back(ans.size()) ;
    }
    for( auto it : ans )cout << it <<" " ;
    cout << endl ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    cout << setprecision(20)  << fixed ;
    int t ; 
    cin>>t ; 
    while(t-- > 0 )
    {
        int n ;
        vs str = {"1" , "10" , "111"};
        // for( auto &it : )
        solve(str) ;
    }
    return 0;
}