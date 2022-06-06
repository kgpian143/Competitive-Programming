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
typedef pair<string, int> psi;  
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
        vpii vp ;
        int a ,  flag = 0 ;
        f(i,0,n)
        {
            cin>>a ;
            if( a == 0 || a == 3 )vp.push_back(make_pair(a,i));
        }
        f(i,0,(int)vp.size()-1)
        {
            // if( vp[i+1].second - )
            if( vp[i+1].first != vp[i].first)
            {
                if((vp[i+1].second - vp[i].second) % 2 == 1 )
                {
                    flag++ ;
                    break;
                }
            }
            else 
            {
               if((vp[i+1].second - vp[i].second ) % 2 == 0 )
                {
                    flag++ ;
                    break;
                } 
            }
        }
        if( flag == 0 )cout<<"YES"<<endl;
        else cout<<"NO"<<endl ;
    }
    return 0;
}