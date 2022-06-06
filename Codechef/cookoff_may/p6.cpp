#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
typedef vector<int> vi; 
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
    while( t-- > 0 )
    {
        int n ;
        cin>>n ;
        vi v(n , 0 );
        f(i,0,n)cin>>v[i] ; 
        sort(v.begin() ,v.end());
        if( n == 4 )
        {
            if( (v[1] - v[0]) > v[2] - v[1] && (v[3] - v[2] ) > v[2] - v[1] )
            {
                cout<<v[1]<<" "<<v[0]<<" "<<v[2]<<" "<<v[3]<<endl ;
            }
            else cout<<v[0]<<" "<<v[2]<<" "<<v[1]<<" "<<v[3]<<endl ;
        }
        else if( n < 4 )
        {
            f(i,0,n)cout<<v[i]<<" ";
            cout<<endl ;
        }
        else 
        {
            for( int i = 0 , j = (n+1)/2; i < (n+1)/2 || j < n ; i++ , j++ )
            {
                if( j == n )cout<<v[i]<<" ";
                else cout<<v[i]<<" "<<v[j]<<" ";
            }
            cout<<endl ;
        }
    }
    return 0;
}