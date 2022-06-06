#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define int long long 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef pair<int, int> pii;  
typedef pair<int, bool> pib;  
typedef unsigned long long ull; 
typedef long double ld; 
typedef vector<pii> vpii; 
vpii v;
int n ,  x ;
int bs( int a )
{
    int l = -1 , h = n ;
    while( h - l > 1 )
    {
        int m = ( h + l )/2 ;
        if( v[m].first <= a)l = m ;
        else h = m ;
    } 
    if(v[l].first == a )return l ;
    else return -1 ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t  = 1;
    // cin>>t ;
    while(t-- > 0 )
    {
        cin>>n>>x;
        mii m ;
        f(i,0,n)
        {
            int a ;
            cin>>a ;
            v.push_back({a , i+1 }) ;
        }
        sort(all(v)) ;
        bool ans = false ;
        int a1  , a2 ;
        for( int i = 0 ; i < n ; i++)
        {
            int pos =  bs( x - v[i].first) ;
            if( pos != -1 && pos != i)
            {
                a1 = v[i].second ;
                a2 = v[bs( x - v[i].first)].second ;
                ans = true ;
                break;
            }
        }
        if(ans)
        {
            if(a1 > a2 )cout<<a2<<" "<<a1 ;
            else cout<<a1<<" "<<a2 ;
        }
        else cout<<"IMPOSSIBLE";
    }
    return 0;
}