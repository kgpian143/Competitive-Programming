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
// int has[1000000] ;
int main()
{
    int n , q , ch = -1 ;
    cin>>n>>q ;
    vl v( n , 0 ) , has( n , 0 ) ;
    f( i , 0 , n )cin>>v[i] ;
    long long int sum = accumulate( v.begin() , v.end() , 0 ) ;
    int flag = 0 , i = 0 ;
    while(q-- > 0 )
    {
        int t ;
        cin>>t ;
        if( t == 1 )
        {
            int index , x ;
            cin>>index>>x ;
            if( flag == 0 )
            {
                sum = sum - v[index-1] + x ;
                v[index-1] = x ;
            }
            else 
            {
                if( has[index-1] > ch  )
                {
                    sum = sum - v[index-1] + x ;
                    v[index-1] = x ;
                    has[index-1] = i ;
                }
                else 
                { 
                    sum = sum + x - flag ;
                    v[index-1] = x ;
                    has[index-1] = i ;
                }
                
            }
        }
        else if( t == 2)
        {
            ch = i ;
            int x ;
            cin>>x ;
            sum = n*1LL*x ;
            flag = x ;
        }
        // for( int  i = 0 ; i < )
        cout<<sum<<endl;
        i++ ;
    }
    return 0;
}