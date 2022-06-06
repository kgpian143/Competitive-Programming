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
        vi v(n , 0 );
        mii m ;
        f(i,0,n)
        {
            cin>>v[i] ;
            m[v[i]] += 1 ;
        }
        if( n == m.size())
        {
           cout<<"YES"<<endl; 
           f(i,0,n)cout<<v[i]<<" ";
           cout<<endl;
           for( int i = v.size()/2  ; i < v.size() ; i++)cout<<v[i]<<" ";
           for( int i = 0 ; i < v.size()/2 ; i++)cout<<v[i]<<" ";
          cout<<endl ;
        }
        else if( m.size() < 3 )cout<<"NO"<<endl ;
        else 
        {
            int flag = 0 ;
            for( auto it : m )
            {
                if( it.second > n/2 )
                {
                    flag++ ;
                    break ;
                }
            }
            if( flag == 0 )
            {
                cout<<"YES"<<endl ;
                vi v1;
                for( auto it : m )
                {
                    for( int i = 0 ; i < it.second ; i++ )
                    {
                        cout<<it.first<<" ";
                        v1.push_back(it.first);
                    }
                    
                }
                cout<<endl ;
                for( int i = v.size()/2  ; i < v.size() ; i++)cout<<v1[i]<<" ";
                for( int i = 0 ; i < v.size()/2 ; i++)cout<<v1[i]<<" ";
                cout<<endl ;
            }
            else 
            cout<<"NO"<<endl ;
        }
    }
    return 0;
}