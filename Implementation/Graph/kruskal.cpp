#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5 ;
int par[N] ;
int size[N] ;
void make( int a )
{
    par[a] = a ;
    size[a] = 1 ;
}

int find( int a )
{
    if( par[a] == a)return a ;
    else return par[a] = find(par[a]) ;
}

void Union( int a , int b )
{
    a = find(a) ;
    b = find(b) ;
    if( size[a] > size[b] )
    {
        par[b] = a ;
        size[a] = max( size[a] ,  size[b] + 1) ;
    }
    else 
    {
        par[a] = b ;
        size[b] = max( size[b] , size[a] + 1) ;
    }
}

int main()
{
    vector< pair< int , pair< int  , int >>> edges ;
    int n ,  k ;
    cin>>n>>k ;
    while( k-- > 0 )
    {
        int u ,  v ,  wt ;
        cin>>u>>v>>wt ;
        edges.push_back({ wt , { u ,  v}}) ;
    }
    sort( edges.begin() , edges.end()) ;
    for( int i = 1 ; i <= k ;  i++ )make(i) ;
    int total_cost = 0 ;
    for( auto it : edges)
    {
        int u = it.second.first ;
        int v = it.second.first ;
        int wt = it.first ;
        if( find(u) == find(v))continue;
        cout<<u<<" "<<v<<endl;
        total_cost += wt ;
    }
    cout<<total_cost ;
}