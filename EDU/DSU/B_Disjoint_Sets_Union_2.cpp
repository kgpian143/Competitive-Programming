#include<bits/stdc++.h>
using namespace std ;
const int N = 3e5 + 5 ;
int par[N] ;
int maxelm[N]  ;
int minelm[N] ;
int size[N] ;
void make( int a )
{
    par[a] = a ;
    size[a] = 1 ;
    maxelm[a] = a ; 
    minelm[a] = a ; 
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
    if( a == b )return ;
    if( size[a] > size[b] )
    {
        par[b] = a ;
        size[a] = size[a] + size[b];
        maxelm[a] = max( maxelm[a] , maxelm[b] );
        minelm[a] = min( minelm[a] , minelm[b] );
    }
    else 
    {
        par[a] = b ;
        size[b] += size[a] ;
        maxelm[b] = max( maxelm[a] , maxelm[b] );
        minelm[b] = min( minelm[a] , minelm[b] );
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n , k ;
    cin>>n>>k ;
    for( int i = 1 ; i <= n ; i++)make(i) ;
    while( k-- > 0 )
    {
        string s ;
        cin>>s ;
        if( s == "union" )
        {
            int a , b ;
            cin>>a>>b ;
            Union(a,b) ;
        }
        else 
        {
            int a ;
            cin>>a ;
            int b = find(a) ;
            cout<<minelm[b]<<" "<<maxelm[b]<<" "<<size[b]<<endl ;
        }
    }
    return 0;
}