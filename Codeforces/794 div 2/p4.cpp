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
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int a , b , c , d  ;
        cin>>a>>b>>c>>d ;
        string s ;
        cin>>s ;
        int cnt1 = 0  , cnt2 = 0  , cnt3 = 0  , cnt4 = 0 ;
        f(i , 0 , s.size() )
        {
            if(s[i] == 'A')cnt1++ ;
            else cnt2++ ;
        }
        f( i , 0 , s.size() - 1)
        {
            if(s[i] == 'A' && s[i+1] == 'B')cnt3++ , i++ ;
        }
        f( i , 0 , s.size() - 1)
        {
            if(s[i] == 'B' && s[i+1] == 'A')cnt4++ , i++ ;
        }
        cout<<cnt1<<cnt2<<cnt3<<cnt4<<endl;
        if( a > cnt1 )cout<<"NO"<<endl;
        else if( b > cnt2 )cout<<"NO"<<endl;
        else if( c > cnt3 )cout<<"NO"<<endl;
        else if( d > cnt4 )cout<<"NO"<<endl;
        else if( (cnt1 - c - d != a) || (cnt2 - c - d != b))cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}