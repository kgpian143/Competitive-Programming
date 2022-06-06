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
    int n ;
    cin>>n ;
    vi v( n , 0 );
    f( i , 0 , n )cin>>v[i] ;
    ll sum = 0 ;
    sum = accumulate( v.begin() , v.end() , sum );
    if( sum % 3 == 0 )
    {
        ll total_cnt = 0 ;
        ll sum1 = sum / 3 ;
        vi cnt( n+1 , 0 ) ;
        ll ans = 0 ;
        for( int i = n - 1 ; i > 0 ; i--)
        {
            ans += v[i] ;
            if( ans == sum1 )cnt[i] = 1 ;
            cnt[i] += cnt[i+1] ;
        }
        ans = 0 ;
        for( int i = 0 ; i < n - 2 ; i++ )
        {
            ans += v[i] ;
            if( ans == sum1)total_cnt += cnt[i+2] ;
        }
        cout<<total_cnt;
    }
    else cout<<0 ;
    return 0;
}