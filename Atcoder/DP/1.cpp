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

vector<string>  solve( vector<string> newpass , vector<string> oldpass)
{
    int n = newpass.size();
    vector<string> ans ;
    for( int i = 0 ; i < n ; i++)
    {
        int ind1 = 0 , ind2 = 0 ;
        while(( ind1 < newpass[i].size() && ind2 < oldpass[i].size()))
        {
            if( oldpass[i][ind2] == 'a')
            {
                if(( newpass[i][ind1] == 'z') || (newpass[i][ind1] == 'a'))
                {
                    ind1++ ;
                    ind2++ ;
                }
                else ind1++ ;
            }
            else
            {
                if( (newpass[i][ind1] == oldpass[i][ind2]) || ((newpass[i][ ind1 ] + 1) == oldpass[i][ind2]))
                {
                    ind1++ ;
                    ind2++ ;
                }
                else ind1++ ;
            }
        }
        if( ind2 == oldpass[i].size() )ans.push_back("YES") ;
        else ans.push_back("NO") ;
    }
    return ans ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t =1 ; 
    // cin>>t ; 
    while(t-- > 0 )
    {
        vs s1 = {"bzz"};
        vs s2 = {"az"};
        vs ans = solve( s1 , s2) ;
        for(auto it : ans )cout << it << "\n" ;
    }
    return 0;
}