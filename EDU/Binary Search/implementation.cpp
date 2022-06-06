#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin() , v.end()

typedef vector<int> vi; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef map<long long, long long> mll;
typedef pair<int, int> pii;  
typedef pair<long long, long long> pll; 
typedef unsigned long long ull; 
typedef long double ld; 
typedef long long ll; 
typedef vector<vector<int>> vvi; 
typedef vector<pii> vpii; 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n , k ;
    cin>>n>>k;
    vi  v( n , 0 ) ;
    f(i,0,n)cin>>v[i] ;
    while( k-- > 0 )
    {
        int a ;
        cin>>a ;
        if(binary_search(all(v), a))cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}