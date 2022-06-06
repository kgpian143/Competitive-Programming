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
        cin>>n ;
        vi v( n+1 , 0 ) ;
        f(i , 0 , n)cin>>v[i+1];
        sort(v.begin() ,  v.end() );
        if( n & 1)cout<<"NO"<<endl;
        else 
        {
            int flag = 0 ;
            vi res ;
            for( int i = 1 , j = n/2 + 1 ; i <= n/2 && j <= n ; i++ , j++  )
            {
                if( j == n )
                {
                    if( v[j] <= v[1])
                    {
                        flag++ ;
                        break;
                    }
                }
                if( v[i] >= v[j] || ( i != 1 && v[i] >= v[j-1]))
                {
                    flag++ ;
                    break; 
                }
                else 
                {
                    res.push_back(v[i]) ; 
                    res.push_back(v[j]) ; 
                }
            }
            if( flag != 0 )cout<<"NO"<<endl;
            else 
            {
                cout<<"YES"<<endl;
                f(i , 0 , res.size() )cout<<res[i]<<" ";
                cout<<endl;
            }
        }
     }
    return 0;
}