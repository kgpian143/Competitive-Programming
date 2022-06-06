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
    int n , k  ;
    cin>>n>>k ;
    long long int ind1 = 0 , ind2 = 0 , sum = 0 , cnt1 = 0 ;
    vi v( n , 0 ) ;
    vi index ;
    f( i , 0 , n )
    {
        cin>>v[i] ;
        if( v[i] == 0 )
        {
            cnt1++ ;
            index.push_back(i) ;
        }
        sum += v[i] ;
    }
    if( sum  < -cnt1*k || sum > 2*cnt1 )cout<<-1<<endl ;
    else 
    {
        if( cnt1 == 1 )v[index[0]] = -sum ;
    }
    return 0;
}