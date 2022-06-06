#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
typedef vector<int> vi; 
typedef vector<string> vs; 
typedef vector<long long int> vl;
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
struct project 
{
    int st_day ;
    int end_day ;
    int reward ;
}; 
bool operator >(project const& ms, int const i)
{
    return ms.end_day > i;
}
bool comp( project p1 , project p2 )
{
    return p1.end_day < p2.end_day ;
}

int main()
{
    // int t ;
    // cin>>t ;
    int n ;
    cin>> n;
    vector<project> A(n);
    vl dp( n , 0 ) ;
    // multimap<int,int> end_day ;
    f(i,0,n)
    {
        cin>>A[i].st_day>>A[i].end_day>>A[i].reward;
    }
    sort( A.begin() , A.end()  , comp);
    dp[0] = A[0].reward ; 
    for( int i = 1 ; i < n ; i++ )
    {
        if( A[i].st_day > A[i-1].end_day )dp[i] = dp[i-1] + A[i].reward ;
        else 
        {
            // int index /= upper_bound(A.begin(), A.begin() + i , A[i].st_day ) - A.begin() ;
            // cout<<index ;
            // dp[i] = max( dp[< i-1] ,  dp[index - 1] + A[i].reward) ;
            int index = -1 ;
            for( int j = i-1 ; j >= 0 ; j-- )
            {
                if(A[j].end_day < A[i].st_day)
                {
                    index = j ;
                    break ;
                }
            }
            long long int a = 0 ;
            if( index == -1 )dp[i] = max( dp[i-1] ,   a + A[i].reward) ;
            else dp[i] = max( dp[i-1] , dp[index] + A[i].reward) ;
        }
    }
    cout<<dp[n-1];
    return 0;
}