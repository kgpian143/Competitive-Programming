#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define int long long 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
typedef vector<int> vi; 
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
    int t = 1 ;
    // cin>>t ;
    while(t-- > 0 )
    {
        int a , b ;
        cin>>a>>b ;
        if( a > b + 1 || a < ((b+1)/2 - 1)) cout<<-1 ;
        else 
        {
            if( a == b )
            {
                while(b-- > 0 )cout<<10;
            }
            else if( a == b + 1 )
            {
                cout<<0;
                while(b-- > 0 )cout<<10;
            }
            else if( b == 2*a + 1  )
            {
                while(a-- > 0 )cout<<"110";
                cout<<1;
            }
            else if( b == 2*a + 2 )
            {
                while(a-- > 0 )cout<<"110";
                cout<<11;
            }
            else
            {
                int k = b - a ;
                a = a - k ;
                while(k-- > 0 )
                {
                    cout<<110;
                }
                while( a-- > 0 )cout<<10;
            }
        }
    }
    return 0;
}