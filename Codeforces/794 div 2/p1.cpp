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
        int n ;
        cin>> n ;
        vi v( n , 0 ) ;
        f( i , 0 , n )cin>>v[i] ;
        int sum = 0 , flag = 0 ;
        sum = accumulate( v.begin() , v.end() , sum ) ;
        f( i, 0 , n )
        {
            if( sum - v[i] == (n-1)*v[i])
            {
                flag++ ;
                break ;
            }
        }
        if( flag == 0 )cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}