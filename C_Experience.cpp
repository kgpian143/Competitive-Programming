#include<bits/stdc++.h>
using namespace std ;
const int N = 3e5 + 5 ;
int par[N] ;
int size[N] ;
int val[N] ;
void make( int a )
{
    par[a] = a ;
    val[a] = 1 ;
    val[a] = 0 ;
}

int find( int a )
{
    if( par[a] == a)return a ;
    else 
    {
        // if( par[par[a]] != par[a])val[a] += val[par[a]] ;
        return  find(par[a]) ;
    }
}

void add( int a , int point )
{
    a = find(a) ;
    val[a] += point ;
}

int getVal( int a )
{
    // int b = find(a) ;
    if( a == par[a])return val[a] ;
    return val[a] + getVal(par[a]) ;
}
void Union( int a , int b )
{
    a = find(a) ;
    b = find(b) ;
    if( a == b )return ;
    if( size[a] < size[b] )
    {
        par[b] = a ;
        // val[a] = val[a] + val[b];
        size[a] += size[b] ;
        val[b] = val[b] - val[a] ;
    }
    else 
    {
        par[a] = b ;
        // val[b] += val[a] ;
        size[b] += size[a] ;
        val[a] -= val[b] ;
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
        if( s == "join" )
        {
            int a , b ;
            cin>>a>>b ;
            Union(a,b) ;
        }
        else if( s == "add")
        {
            int a , amount ;
            cin>>a>>amount ;
            add(a , amount);
        }
        else 
        {
            int a ;
            cin>>a ;
            cout<<getVal(a) << endl;
        }
        
    }
    return 0;
}
/*
add 1 100
join 1 2 
get 2
0
0
get 1
100
100
add 2 50
get 2 
50
50
join 2 3
add 3 10
get 3
10
10
get 2
60
60
add 4 100
get 4
100
100
join 4 5
add 5 200
get 4
300
300
join 5 2 
get 2
60
1
add 1 30
get 5
230
1
join 1 5 */