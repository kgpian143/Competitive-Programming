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
typedef vector<vector<int>> vvl; 
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


bool compare(pair<int, int>& a, pair<int, int>& b) {
    if (a.first != b.first) {
        return a.first < b.first;  // Sort in ascending order based on the first element
    } else {
        return a.second > b.second; // Sort in descending order based on the second element
    }
}
int scoreAndCost(int n, vector<int> &a, vector<int> &b, int x) {
    // Write your code here.

    vector<pair<int, int>> vp(n) ;
    for( int i=0;i<n; i++){
        vp[i].first = b[i] ;
        vp[i].second = a[i] ;
    }
    sort( vp.begin(), vp.end() , compare) ;
    vector<int> pref( n + 1 , 0 ) ;
    for( int i = 1 ; i <= n ; i++ )
    {
        pref[i] = pref[i-1] + vp[i-1].second ;
    }
     if(pref[n] < x) return -1;
    int ind = lower_bound( pref.begin(), pref.end() , x ) - pref.begin() ;
    int mx = vp[ind-1].second ;
    for(int i=ind; i<n; i++)
    {
        if( vp[i].second > mx ) mx = vp[i].second ;
    }
    mx = pref[ind] + mx  - x ;
    int sm = 0 ;
    int ans = ind - 2 ;
    for( int i = ind - 1 ; i >= 0 ; i-- ){
        sm += vp[i].second ;
        if( sm > mx ){
            ans = i ;
            break;
        }
    }

    return vp[ans].first ;

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ; 
    cin>>t ; 
    while(t-- > 0 )
    {
        int n , x ; 
        cin >> n >> x ; 
        vi A(n) , B(n) ; 
        f( i , 0 , n )cin >> A[i] ;
        f( i , 0 , n )cin >> B[i] ;
        
        
        cout << scoreAndCost( n , A , B , x) << "\n" ;
     }
    return 0;
}
