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
#define getv(v,n) for( int i = 0 ; i < n ; i++)cin>>v[i];
#define putv(v) for(auto it : v )cout<<it<<' ';
// #define getvv(v,n,n)for(int i = 0 ; i < n ; i++ )f(j,0 ,n)cin>>v[i][j] 
const int N = 2e5 + 5; 
const int inf = 1e9 + 6 ;
void solve(vector<vector<int> > &A) {
    // vector<int> ans ;
    // int n = A.size() ;
    int n = A[0].size();
    vector<vector<bool>> marked( n ,  vector<bool> ( n , false ) ) ; 
    vector<vector<bool>> marked1( n ,  vector<bool> ( n , false ) ) ; 
    int max_ele = A[0][0 ];
    for( int i = 0 ;  i< n ; i++ )
    {
        for( int j = 0 ;  j < n ; j++ )
        {
            if( A[i][j] > max_ele) max_ele = A[i][j] ;
        }
    }
    max_ele++ ;
    int dc[] = { 1 , 0 , -1 , 0 };
    int dr[] = { 0 , 1 , 0 , -1 };
    int x = 0, y = 0, di = 0 , x1 = 0 , y1 = n-1 ,  di1 = 1;
    for (int i = 0; i < n * n; i++) {
        // ans.push_back(A[x][y]);
        A[x][y] = max_ele *( A[x1][y1] % max_ele) + A[x][y] ;
        marked[x][y] = true;
         int newX = x + dr[di];
        int newY = y + dc[di];
       marked1[x1][y1] = true;
        int newX1 = x1 + dr[di1];
        int newY1 = y1 + dc[di1];
        if (0 <= newX && newX < n && 0 <= newY && newY < n
            && !marked[newX][newY]) {
            x = newX;
            y = newY;
        }
        else {
            di = (di + 1) % 4;
            x += dr[di];
            y += dc[di];
        }
        // if( marked)
        if (0 <= newX1 && newX1 < n && 0 <= newY1 && newY1 < n
            && !marked1[newX1][newY1]) {
            x1 = newX1;
            y1 = newY1;
        }
        else {
            di1 = (di1 + 1) % 4;
            x1 += dr[di1];
            y1 += dc[di1];
        }
    }
    for( int i = 0 ; i < n ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            A[i][j] = A[i][j] / max_ele  ;
        }
    }
    // return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n  ;
        cin>>n ;
        vvi A( n ,  vi( n , 0 )) ;
        f( i , 0 ,  n)
        {
            f( j , 0 , n)cin>>A[i][j] ;
        }
        solve( A);
         f( i , 0 ,  n)
        {
            f( j , 0 , n)cout<<A[i][j] << " ";
            cout<<endl;
        }
    }
    return 0;
}