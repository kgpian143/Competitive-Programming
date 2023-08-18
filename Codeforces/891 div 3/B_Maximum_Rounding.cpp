#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define int  long long  
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<int> vl;
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii;
typedef map<int, int> mll;
typedef pair<int, int> pii;  
typedef pair<int, bool> pib; 
typedef pair<int, int> pll; 
typedef unsigned int ull; 
typedef long double ld; 
typedef int ll; 
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;
const int N = 1e5 + 5 ;

void solve()
{
    string s ; 
    cin >> s ;
    string ans ;
    int ind = -1 ;
    for( int i = 0 ; i < s.size() ; i++ )
    {
        if(  s[i] > '4' )
        {
            ind = i ;
            while( ( ind > 0 ) && ( s[ind-1] > '3')) 
            {
                ind-- ;
            }
            if( ind == 0)
            {
                ans.push_back('1') ;
            }
            else 
            {
                s[ind-1] += 1 ;
                for( int j = 0 ; j < ind ; j++ )
                {
                    ans.push_back(s[j]) ;
                }
            }
            for( int j = ind ; j < s.size() ; j++ )
            {
                ans.push_back('0') ;
            }
            cout << ans << '\n';
            return ;
        }
    }
    if( ind == -1)
    {
        cout << s << endl ; 
        return ;
    }
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ; 
    cin>>t ; 
    while(t-- > 0 )
    {
        solve() ;
    }
    return 0;
}