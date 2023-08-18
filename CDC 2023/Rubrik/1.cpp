#include<bits/stdc++.h>
using namespace std ;

void solve()
{
    int n , x, y ;
    cin >> n >> x >> y ; 
    vector<int> v( n, 0 );
    for( int i = 0 ; i < n ; i++ )
    {
        cin >> v[i] ;
    }
    map<int , int > m ; 
    vector<int> dp( n + 1 , 0 );
    dp[1] =  1;
    for( int i = 2 ; i <= n ; i++ )
    {
        m[v[i-1]]++ ;
       dp[i] = dp[i-1] + i - m[v[i-1]] ; 
    }
    cout << dp[n] << endl ;
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