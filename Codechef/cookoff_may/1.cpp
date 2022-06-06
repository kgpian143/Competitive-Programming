#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
typedef vector<int> vi; 
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

int main()
{
    int t ;
    cin>>t ;
    while( t -- > 0 )
    {
        int n ; 
        cin>>n ;
        if( n <= 4 && n >= 2 )cout<<n-1<<endl ;
        else cout<<n<<endl ;
    }
    return 0;
}