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
int cnt[N] ;
int ind[N] ;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n ;
    cin>>n ;
    cnt[0] = 1 ;
    for (int  i = 0; i < n; i++)
    {
        int a ;
        cin>>a ;
        ind[a] = i+1 ;
    }
    for( int i = 1 ; i <= n ; i++ )
    {
        if( ind[i] > ind[i-1] )cnt[i] = cnt[i-1] ;
        else cnt[i] = cnt[i-1] + 1 ;
    }
    cout<<cnt[n]<<endl;
    return 0;
}