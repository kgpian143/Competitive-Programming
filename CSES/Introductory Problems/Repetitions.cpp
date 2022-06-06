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
    string s ;
    cin>>s;
    int cnt = 1 , max_cnt = 1 ;
    for( int i = 0 ; i < (int)s.size() - 1 ; i++ )
    {
        if( s[i] != s[i+1])
        {
            max_cnt = max( max_cnt , cnt ) ;
            cnt =  1 ;
        }
        else cnt++ ;
    }
    max_cnt = max( cnt , max_cnt) ;
    cout<<max_cnt ;
    return 0;
}