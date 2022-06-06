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
    if( t == 1)cout<<1<<endl ;
    else if( t <= 3 )cout<<"NO SOLUTION\n" ;
    else 
    {
        for( int i = 1 ,  j = t/2 + 1 ; i <= t / 2 || j <= t ; i++ , j++ )
        {
            if( i > t/2)cout<<j;
            else cout<<j<<" "<<i<<" ";
        }
    }
    return 0;
}