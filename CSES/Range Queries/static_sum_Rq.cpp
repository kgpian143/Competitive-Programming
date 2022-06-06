#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
typedef vector<int> vi; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<long long> vll;
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
    // int t ;
    // cin>>t ;
    int n , q;
    cin>> n >> q;
    vll a(n+1,0) ;
    f(i,1,n+1)
    {
        cin>>a[i] ;
        a[i] += a[i-1] ;
    }
    while( q-- > 0)
    {
        int a1 , b ;
        cin>>a1>>b ;
        cout<<a[b]-a[a1-1]<<endl ;
    }
    return 0;
}