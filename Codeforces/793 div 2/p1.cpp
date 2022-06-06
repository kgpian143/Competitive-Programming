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
       int n ;
       cin>>n ;
       string s ;
       cin>>s ;
       int k = (s.size() - 1)/2 ;
       int cnt = 0 ;
       for( int i = k ; i < s.size() ; i++ )
       {
           if( s[i] == s[k] )cnt++ ;
           else break ;
       }
       for( int i = k-1 ; i >= 0 ; i-- )
       {
           if( s[i] == s[k] )cnt++ ;
           else break ;
       }
       cout<<cnt<<endl;
    }
    return 0;
}