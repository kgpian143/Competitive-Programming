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
        string s  ;
        cin>>s ;
        int cnt1 = 0 , cnt2 = 0 ;
        for( int i = 0 ; i < s.size() ; i++ )
        {
            if( s[i] == '0')cnt1++ ;   
        }
        int ans = max( cnt1 , cnt2 ) ;
        int i = 0 , j = (int)s.size() - 1 ;
        while( cnt1 > cnt2)
        {
            if( s[i] == '0' )
            {
                cnt1-- ;
                ans = cnt1  ;
                i++ ;
                continue;
            }
            else 
            {
                if(s[j] == '0')
                {
                    cnt1-- ;
                    ans = cnt1 ;
                    j-- ;
                    continue;
                }
                else 
                {
                    int k = i ,  k1 = j ;
                    int c2 = cnt2 ;
                    while( s[k] != '0' && s[k1] != '0')
                    {
                        
                    }
                }
            }
        }
        cout<<ans<<endl ;
    }
    return 0;
}