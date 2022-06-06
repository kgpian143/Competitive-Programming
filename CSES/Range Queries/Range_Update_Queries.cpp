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
const int N = 2e5 + 5;
long long int table[4*N];

void build(vector<int> &v,  int ind , int st, int se )
{
    if (st == se)
    {
        table[ind] = v[st];
    }
    else
    {
        int tm = (st + se) / 2;
        build(v, ind * 2, st, tm);
        build(v, ind * 2 + 1, tm + 1, se);
        table[ind] = 0 ;
    }
}
// void propagate( int ind , int st , int se )
// {
//     if( st == se )return  ;
    
// }
long long int findvalue(int pos, int st, int se, int ind)
{
    // propagate( ind , st , se ) ;
    if (st == se)
        return table[ind];
    if (table[ind] != 0)
    {
        int left = 2 * ind;
        int right = 2 * ind + 1;
        table[left] += table[ind];
        table[right] += table[ind];
        table[ind] = 0;
    }
    int mid = (st + se) / 2;
    if (pos >= st && pos <= mid)
    {
        return findvalue(pos, st, mid, 2 * ind);
    }
    else
        return findvalue(pos, mid + 1, se, 2 * ind + 1);
}

void update(int val, int st, int se, int l , int r , int ind )
{
    if( l > se || r < st )return ;
    if( l <= st && r >= se )
    {
        table[ind] += val ;
    }
    else if( st == se)table[ind] += val ;
    else 
    {
        int mid = (st + se)/2 ;
        update( val , st , mid , l , r , 2*ind) ;
        update( val , mid +1 , se ,  l , r , 2*ind + 1 ) ;
    }
}
int main()
{
    int n , q ;
    cin>>n>>q ;
    vi  v( n+1 , 0 ) ;
    // f( i , 1 , n+1)cin>>v[i] ;
    build( v , 1 , 0 , n-1);
    while(q-- > 0 )
    {
        int t ;
        cin>>t ;
        if( t == 1 )
        {
            int a  , b  ,  u ;
            cin>>a>>b>>u ;
            update( u , 0 , n-1 , a , b-1 , 1 ) ;
        }
        else 
        {
            int k ;
            cin>> k;
            cout<< findvalue( k , 0 , n-1 , 1) <<endl;
        }
    }
    return 0;
}