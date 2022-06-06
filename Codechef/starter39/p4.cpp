#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
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
        int n , k , flag = 0;
        cin>>n>>k ;
        vpii graph[n+1] ;
        for( int i = 1 ; i < n ; i++)
        {
            int u , v ,  x ;
            cin>>u>>v>>x ;
            graph[u].push_back({v, x}) ;
            graph[v].push_back({ u , x }) ;
        }
        int cnt = 0 , inf = 1 ;
        vb infect_city( n+1 , false ) ;
        infect_city[1] = true ;
        queue<int> q ;
        q.push(1) ;
        while(1)
        {
            //  q.pop() ;
             int a = q.front() ;
            //  cout<<a;
             for( int i = 0 ; i < graph[a].size() ; i++ )
             {

                 if( graph[a][i].second == 0 )
                 {
                     q.push(graph[a][i].first) ;
                     infect_city[graph[a][i].first] = true ;
                     inf++ ;
                     cout<<"inf"<<inf<<endl;
                 }
                 else 
                 {
                     cnt++ ;
                 }
             }
             q.pop() ;
             if( inf > k  )
             {
                 flag++ ;
                 break ;
             }
             if( q.empty())break ;
        }
        if( flag != 0 )cout<<cnt<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}