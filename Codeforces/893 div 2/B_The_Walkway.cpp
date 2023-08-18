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
    int n ;
    cin >> n ;
    int m , d ;
    cin >> m >> d ;
    vi v(m) ;
    for( int i = 0 ; i < m ; i++ )
    {
        cin >> v[i] ;
    }
    sort(all(v)) ;
    int ans = 1 ;
    int ind = 1 ;
    for( int i = 0 ; i < m ; i++ )
    {
        if( (v[0] == 1 ) && i == 0  )continue; 
        int dif = v[i] - ind - 1;
        ans += dif/ d ;
        ans += 1;
        ind = v[i] ;
    }
    int dif = n - v[m-1] - 1;
    ans += dif/d ;
    int cnt = 0 ; 
    if( ((v[1] - 2 ) / d  + 1 ) == ( ( v[0] - 2 ) / d + ( v[1] - v[0] - 1) / d  + 1 ) )cnt++ ; 
    for( int i = 1 ; i < m-1 ; i++)
    {
        if( ((v[i+1] - v[i-1] - 1 ) / d  + 1 ) == ( ( v[i] - v[i-1] - 1 ) / d + ( v[i+1] - v[i] - 1) / d  + 1 ) )
        {
            cnt++ ;
        }
    }

    if(((n - v[m-2] ) / d  + 1 ) == ( ( n - v[m-1]) / d + ( v[m-1] - v[m-2] - 1) / d  + 1 ))cnt++ ; 
    if( cnt == 0 ) 
    {
        cout << ans << sp << cnt << endl ;
    }
    else cout << ans - 1  << sp << cnt << endl ;
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