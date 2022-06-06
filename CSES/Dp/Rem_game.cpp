#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
typedef vector<int> vi; 
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
int solve(  vi v  ,  int st ,  int n )
{
    if( st == n-1 )return v[n-1] ;
    else 
    {
        if( v[0] > v[n-1])
        {
            if( v[1] > v[n-2] )return v[0] + solve( v , st+2 , n ) ;
            else return v[0] + solve( v , st+1 , n-1);
        }
        else
        {
            if( v[1] > v[n-2] )return v[n-1] + solve( v , st+2 , n ) ;
            else return v[n-1] + solve( v , st+1 , n-1);
        }
    }
}
int main()
{
    // int t ;
    // cin>>t ;
    int n ;
    cin>>n ;
    vi v(n , 0) ;
    f(i,0,n)cin>>v[i] ;
    int k = solve(  v ,  0  , n ) ;
    return 0;
}