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
        vi v(n , 0 ) ;
        f( i , 0 , n)cin>>v[i] ;
        int m ;
        cin>>m ;
        vi v1(m , 0 ) ;
        f( i , 0 , m)cin>>v1[i] ;
        sort( v.begin() , v.end()) ;
        sort( v1.begin() , v1.end()) ;
        if( v[v.size() - 1 ] > v1[v1.size() - 1])
        {
            cout<<"Alice"<<endl;
            cout<<"Alice"<<endl;
        }
        else if( v[v.size() - 1 ] < v1[v1.size() - 1])
        {
            cout<<"Bob"<<endl;
            cout<<"Bob"<<endl;
        }
        else 
        {
            cout<<"Alice"<<endl;
            cout<<"Bob"<<endl;
        }

    }
    return 0;
}