#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef map<long long, long long> mll;
typedef pair<int, int> pii;  
typedef pair<int, bool> pib;  
typedef pair<long long, long long> pll; 
typedef unsigned long long ull; 
typedef long double ld; 
typedef long long ll; 
typedef vector<vector<int>> vvi; 
typedef vector<pii> vpii; 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n , k  ;
        string s ; 
        cin>>n>>k;
        cin>>s ;
        int ind1 = -1 ,  ind2 = -1 ,  cnt = 0 ;
        for( int i = 0 ; i < s.size() ; i++ )
        {
            if( s[i] == '1')
            {
                if( ind1 == -1 )ind1 = i ;
                ind2 = i ;
                cnt++ ;
            }
        }
        if( cnt == 0 )cout<<0<<endl;
        else if( cnt == 1 )
        {
            if( k >= n - 1 - ind2 )cout<<1<<endl;
            else if( k >= ind1 )cout<<10<<endl;
            else cout<<11<<endl;
        }
        else 
        {
            if( k >= ind1 + n - 1 - ind2 )
            {
                cout<<11*(cnt-1)<<endl;
            }
            else if( k >=  n - 1 - ind2 )cout<<(11*(cnt - 1 ) + 1)<<endl;
            else if( k >= ind1 )cout<<( 11 * ( cnt - 1 ) + 10 )<<endl;
            else 
            {
                cout<<11*cnt<<endl ;
            }
        }
    }
    return 0;
}