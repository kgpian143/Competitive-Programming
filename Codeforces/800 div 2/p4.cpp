#include<bits/stdc++.h>
using namespace std ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long 
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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
const int N = 2e5 + 5; 

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n ;
        cin>>n ;
        vpii r(n+1,{0,0}) ;
        vi  par( n+1 , 0 ) , hsh(n + 1,0) ;
        vb vis(n+1 , false) ;
        par[1] = 1 ;
        f( i , 1 , n )
        {
            cin>>par[i+1];
            hsh[par[i+1]]++ ;
        }
        f( i , 0 , n )cin>>r[i+1].first>>r[i+1].second;
        queue<int> q ;
        for( int i = 1 ; i <= n ; i++ )
        {
            if(hsh[i] == 0 )q.push(i) ;
        }
        int cnt = 0 ;
        while(!(q.empty()))
        {
            int a = q.front() ;
            q.pop() ;
            if(vis[a])continue;
            vis[a] = true  ;
            while(1)
            {
                if(vis[par[a]])
                {
                    cnt++ ;
                    break;
                }
                if(r[par[a]].first > r[a].second)
                {
                    cnt++ ;
                    q.push(par[a]) ;
                    break;
                }
                a = par[a] ;
                vis[a] = true  ;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}