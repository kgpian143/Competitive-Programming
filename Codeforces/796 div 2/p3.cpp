#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define int long long 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
typedef vector<int> vi; 
typedef vector<char> vch; 
typedef vector<bool> vb; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef pair<int, int> pii;  
typedef pair<int, bool> pib;  
typedef unsigned long long ull; 
typedef long double ld; 
typedef vector<pii> vpii; 

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n ; 
        cin>>n ;
        map<char, int> m ;
        for( int i = 0 ; i < 2*n + 1 ; i++  )
        {
            string s ;
            cin>>s ;
            for( int i = 0 ; i < s.size() ;i++ )
            {
                m[s[i]]++ ;
            }
        }
        for( char ch = 'a' ; ch <= 'z' ; ch++ )
        {
            if( m[ch] % 2 == 1 )
            {
                cout<<ch<<endl;
                break;
            }
        }
    }
    return 0;
}