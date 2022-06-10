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
    while( t-- > 0 )
    {
        int n , m ;
        cin>>n>>m ;
        int flag = 0 ;
        // int cnt = 0 , min1 = INT_MAX , max1 = INT_MIN ; 
        vi v( n , 0 ) ;
        for( int  i = 0 ; i < n ; i++ )cin>>v[i] ;
        sort(v.begin() , v.end() );
        long long int sum = 0;
        for( int i = 0 ;  i < n ; i++ )
        {
            sum += v[i] ;
        }
        sum = sum - v[0]  + v[n-1];
        if( n > m )flag++ ;
        else 
        {
             if( sum > m - n )flag++ ;
        }
        flag == 0 ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}