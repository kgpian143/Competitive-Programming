#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef map<long long, long long> mll;
typedef pair<int, int> pii;  
typedef pair<int, bool> pib;  
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
       vpii v ;
       mii m ;
       f(i , 0 , n )
       {
           int a ;
           cin>>a ;
           v.push_back( {a ,  i+1} );
           m[a]++ ;
       }
       sort(all(v)) ;
       vi ans ;
       int flag  = 0 ;
       for( int i = 0 ; i < n ; i++ )
       {
           if( m[v[i].first] == 1 )
           {
               flag++ ;
               break ;
           }
           if( m[v[i].first] % 2 == 1 )
           {
               int j = i + m[v[i].first] - 1 ;
               int mid = (j + i)/2 ;
               swap( v[mid] , v[mid+1]) ;
               while( j >= i )
               {
                   ans.push_back(v[j].second) ;
                   j-- ;
               }   
           }
           else 
           {
               int j = i + m[v[i].first] - 1 ;
               while( j >= i )
               {
                   ans.push_back(v[j].second) ;
                   j-- ;
               } 
           }
           i = i + m[v[i].first] - 1 ;
       } 
       if( flag != 0 )cout<<-1<<endl;
       else 
       {
           for( auto it : ans )cout<<it<<" ";
           cout<<endl;
       }
    }
    return 0;
}