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
         int x , y ;
         cin>>y>>x ;
         long long int ans ;
         if( x <= y )
         {
             if((y & 1) == 0 )
             {
                 ans =  (y)*1LL*y - x + 1 ;
             }
             else 
             {
                ans = (y-1)*1LL*(y-1) + x ;
             }
         }
         else 
         {
             if((x & 1) == 1 )
             {
                 ans =  (x)*1LL*x - y + 1 ;
             }
             else 
             {
                ans = (x-1)*1LL*(x-1) + y ;
             }
         }
         cout<<ans<<endl;
    }
    return 0;
}