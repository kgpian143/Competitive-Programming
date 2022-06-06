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
    int m , sum ;
    cin>>m>>sum ;
    int k = 9*m ;
    int k1 = 9*m ;
    if( m == 1 && sum ==0 )cout<<0<<" "<<0;
    else if( k < sum || sum == 0 )cout<<-1<<" "<<-1;
    else if( k == sum )
    {
        string s ;
        for( int i = 1 ; i <= m ; i++ )s.push_back('9') ;
        cout<<s<<" "<<s ;
    }
    else 
    {
        string s ;
        f( i , 0 , m )s.push_back('9') ;
        string s1 = s;
        for( int i = s.size() - 1 ; i >= 0 ; i-- )
        {
            if( k - sum <=  9 )
            {
                s[i] = '0' + 9 - k + sum ; 
                break ;
            }
            k -= 9 ;
            s[i] = '0' ;
        }
        for( int i = 0 ; i < s1.size() ; i++ )
        {
            if(i == 0 )
            {
                if( k1 - sum < 9 )
                {
                    s1[i] = '0' + 9 - k1 + sum ;
                     break ;
                }
                else 
                 s1[i] = '1' ;
                 k1 = k1 - 8 ;
            }
            else
            {
                if( k1 - sum <= 9 )
                {
                    s1[i] = '0' + 9 - k1 + sum ;
                    break ;
                }
                s1[i] = '0' ;
                k1 = k1 - 9 ;
            }
        }
        cout<<s1<<" "<<s ;
    }
    return 0;
}