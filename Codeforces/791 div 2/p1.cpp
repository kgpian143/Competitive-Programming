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
        long long int n; 
        cin>>n ;
        if( n % 2 != 0 || n < 4 )cout<<-1<<endl ;
        else 
        {
            long long int x , y ;
            if( n % 4 == 0 )x = n/4 ;
            else x = (n/4)  ;
            if( n % 6 == 0 )y = n/6 ;
            else y = (n/6) + 1  ;
            cout<<y<<" "<<x<<endl;
        }
    }
    return 0;
}