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

void solve()
{
    int a , b , c ;
    cin >> a >> b >> c ;
    if( a > b )
    {
        cout << "First" <<endl;
        return ;
    }
    else if( b > a )
    {
        cout << "Second" << endl ;
        return ;
    }
    if( a == b )
    {
        if( c & 1 )cout << "First" <<endl ;
        else cout << "Second" << endl ;
    }
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