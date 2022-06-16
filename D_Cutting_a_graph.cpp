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
int par[N] ;
int size[N] ;
void make(int a)
{
    par[a] = a;
    size[a] = 1;
}

int find(int a)
{
    if (par[a] == a)
        return a;
    else
        return par[a] = find(par[a]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (size[a] < size[b])
        swap(a, b);
    par[b] = a;
    size[a] += size[b] ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int n ,  e , k ;
    vpii g;
    cin>>n >> e >> k ;
    f( i, 0 , e )
    {
        int a , b ;
        cin>>a>>b ;
        g.push_back({a,b}) ;
    }
    vs vstr ;
    vi arr_u , arr_v ;
    vs ans ;
    for( int i = 0 ; i < k ; i++ )
    {
        string s ;
        int u , v  ;
        cin>>s>>u>>v ;
        vstr.push_back(s) ;
        arr_u.push_back(u) ;
        arr_v.push_back(v) ;
    }
    f( i , 0 , n )make(i+1) ;
    for( int j = k-1 ; j >= 0 ; j--)
    {
        // cout<<1 ;
        if( vstr[j] == "ask" )
        {
            if( find(arr_u[j]) == find(arr_v[j]) )ans.push_back("YES\n");
            else ans.push_back("NO\n") ;
        }
        else 
        {
            Union(arr_u[j] , arr_v[j] );
        }
    }
    reverse(all(ans)) ;
    for( auto it : ans)cout<<it;
    return 0;
}