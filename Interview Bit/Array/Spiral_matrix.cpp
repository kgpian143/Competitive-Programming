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
vector<int> spiralOrder(const vector<vector<int> > &A) {
    vector<int> ans ;
    int m = A.size() ;
    int n = A[0].size();
    vector<vector<bool>> marked( m ,  vector<bool> ( n , false ) ) ; 
    int dc[] = { 1 , 0 , -1 , 0 };
    int dr[] = { 0 , 1 , 0 , -1 };
    int x = 0, y = 0, di = 0;
    for (int i = 0; i < m * n; i++) {
        ans.push_back(A[x][y]);
        marked[x][y] = true;
        int newX = x + dr[di];
        int newY = y + dc[di];
        if (0 <= newX && newX < m && 0 <= newY && newY < n
            && !marked[newX][newY]) {
            x = newX;
            y = newY;
        }
        else {
            di = (di + 1) % 4;
            x += dr[di];
            y += dc[di];
        }
    }
    return ans;
} 

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n , m ;
        cin>>m>>n ;
        vvi A( m , vi(n)) ;
        for( int i = 0 ; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j++) 
            {
                cin>>A[i][j] ;
            }
        }
        vi  ans = spiralOrder(A) ;
        for( auto it : ans )cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}