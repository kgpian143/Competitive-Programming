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
    int t ;
    cin>>t ;
    while(t-- > 0 )
    { 
        int l1 , r1 , l2 , r2 ;
        cin>>l1>>r1>>l2>>r2;
        int cnt ;
        if( l1 >= l2  && l1 <= r2)cnt = l1 ;
        else if( l2 >= l1&& l2 <= r1)cnt = l2 ;
        else cnt = l1 + l2 ;
        cout<<cnt<<endl ;
    }
    return 0;
}