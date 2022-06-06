#include<bits/stdc++.h>
using namespace std ;
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
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n , k ;
    cin>>n ;
    for( int i = 1 ; i <= n ; i++)make(i) ;
    return 0;
}