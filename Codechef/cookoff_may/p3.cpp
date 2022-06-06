#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
typedef vector<int> vi; 
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

int main()
{
    int t ;
    cin>>t ;
    while( t -- > 0 )
    {
        int n ;
        cin>>n ;
        vi v(n,0);
        f(i,0,n)cin>>v[i] ; 
        sort(v.begin() , v.end());
        int d1 ,  d2 , flag = 0  ;
        // int d2 = v1[2] - v1[1] ;
        f(i,0,n-2)
        {
            d1 = v[i+1] - v[i] ;
            d2 = v[i+2] - v[i+1];
            // if( d1 == )
            if(d1 == 2*d2 || d2 == 2*d1)continue;
            else 
            {
                cout<<"NO"<<endl;
                flag++ ;
                break ;
            }
        }
        if( flag == 0 )cout<<"YES"<<endl ;
    }
    return 0;
}