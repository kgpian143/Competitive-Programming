#include<bits/stdc++.h>
using namespace std ;

#define int  long long  

bool comparator(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first < b.first) {
        return true; // Sort in increasing order of the first element
    } else if (a.first == b.first) {
        return a.second > b.second; // Sort in decreasing order of the second element
    }
    return false;
}
void solve()
{
    int b , s ;
    cin >> b >> s ;

    int n ;
    cin >> n ;
    vector<pair < int , int >> h( n , { 0 , 0}) ;

    for( int i = 0 ; i < n ; i++)
    {
        cin >> h[i].second >> h[i].first ;
    }
    sort( h.begin() , h.end() , comparator ) ;
    
    vector<int> pref1( n + 1 , 0 ) , pref2( n + 1 , 0 ) ; 

    for( int i = 1 ; i <= n ; i++)
    {
        pref1[i] = pref1[i-1] + h[i-1].first ;
        pref2[i] = pref2[i-1] + h[i-1].second ;
    }
    int ans = -1 ;
    for( int i = 0 ; i < n - b ; i++ )
    {
        int cnt = 0 ;
        int a = s ;
        if( a > pref2[i] )
        {
            cnt += i ;
            a -= pref2[i] ; 
        }
        else 
        {
            int ind = upper_bound( pref2.begin() , pref2.end() , a ) - pref2.begin();
            cnt += ind - 1; 
            ans = max( ans , ind ) ; 
            break; 
        }
        if( a >= ( pref1[i+b] - pref1[i])) {
            cnt += b ;
             a -= ( pref1[i+b] - pref1[i]) ;
        }
        else 
        {
            int ind = upper_bound( pref1.begin() , pref1.end() , a + pref1[i]) - pref1.begin();
            cnt += (ind - i) - 1 ; 
            ans = max( ans , cnt ) ;
            break; 
        }
        int ind = upper_bound( pref2.begin() , pref2.end() , a + pref2[i+b] ) - pref2.begin() ;
        cnt = ind - 1  ; 
        ans = max( ans , cnt ) ; 
    }

    cout << ans << endl ;
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t = 1 ; 
    // cin>>t ; 
    while(t-- > 0 )
    {
        solve() ;
    }
    return 0;
}