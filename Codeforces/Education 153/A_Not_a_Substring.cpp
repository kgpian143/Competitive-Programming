#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define int  long long  
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define pb push_back 
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

void solve()
{
    string s ;
    cin >> s ;
    int n = s.size() ;
    // if(s.size() == 1)
    // {
    //     no
    //     return ;
    // }
    // if(s.size() == 2 && s == "()")
    // {
    //     no
    //     return ;
    // }

    // if( s == "())")
    // {
    //     yes
    //     cout << "()()()" << endl ;
    //     return ;
    // }
    // int diff = 0 ;
    // int cnt1 = 0 , cnt2 = 0 ;
    // for( auto it : s )
    // {
    //     if( it == '(') cnt1++ ;
    //     else cnt2++ ;
    //     diff = max( diff , abs(cnt1 - cnt2 )) ;
    // }


        string s1 , s2  ;
        for( int i = 0 ; i < n ; i++ )
        {
            s1.push_back('(') ;
        }
        for( int i = 0 ; i < n ; i++ )
        {
            s1.push_back(')') ;
        }
        for( int i = 0 ; i < n ; i++ )
        {
            s2.pb('(');
            s2.pb(')');
        }
        if( (s1.find(s) == string :: npos))
        {
            yes
            cout << s1 << endl ;
        }
        else if( s2.find(s) == string :: npos )
        {
            yes 
            cout << s2 << endl ;
        }
        else no 
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
        solve() ;
    }
    return 0;
}