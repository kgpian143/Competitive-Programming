#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
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
    int n ;
    cin>>n ;
    vi v( n , 0 );
    int mx1 = INT_MIN , ind;
    f( i , 0 , n )
    {
        cin>>v[i] ;
        if( v[i] > mx1 )
        {
            mx1 = v[i];
            ind = i ;
        }
    }
    long long int cnt = 0 ;
    for( int i = 1 ; i < ind ; i++ )
    {
        if(v[i] < v[i-1])cnt += 1LL*v[i-1] - v[i]  ;
    }
    for( int i = ind+1 ; i < n ; i++ )
    {
        cnt += 1LL*mx1 - v[i]  ;
    }
    cout<<cnt ;
    return 0;
}