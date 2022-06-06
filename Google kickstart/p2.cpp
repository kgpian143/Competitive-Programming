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
    int t1 = 1 ;
    while(t-- > 0 )
    {
        int n , x , y ;
        cin>>n>>x>>y ;
        if( (n*(n+1)/2) % ( x + y ) != 0)
        {
            cout<<"Case #"<<t1<<": IMPOSSIBLE"<<endl;
            t1++ ;
        }
        else 
        {
            cout<<"Case #"<<t1<<": POSSIBLE"<<endl;
            t1++ ;
            int sum = ((n)*(n+1)*1LL*x/(2*(x+y)))  ;
            if( sum <= n )
            {
                cout<<1<<endl;
                cout<<sum<<endl ;
            }
            else 
            {
                int k1 = 0 , num = n ;
                vector<int> nums ;
                while( k1 < sum  )
                {
                    if( k1 + num > sum )
                    {
                        nums.push_back(sum - k1) ;
                        break ;
                    }
                    else 
                    {
                        nums.push_back(num) ;
                        k1 += num ;
                        num-- ;
                        // nums.push_back()
                    }
                }
                cout<<nums.size()<<endl;
                for( int i = nums.size() - 1 ; i >= 0 ; i-- )
                {
                    cout<<nums[i]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}