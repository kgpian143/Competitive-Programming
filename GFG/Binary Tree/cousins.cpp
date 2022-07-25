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
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
vector<int> solve(TreeNode* A, int B) {
    vector< int > ans ;
    map< int , int > par ;
    par[1] = 1 ;
    int level = -1 ;
    queue< pair< TreeNode* , int >> q ;
    q.push({ A , 0 }) ;
    while( !q.empty() )
    {
        pair< TreeNode* , int >  p  = q.front(); 
        q.pop() ;

        if( p.first->val == B )
        {
            level = p.second ;
            // par[B] =  ;
            // break ;
        } 
        if( p.first->left )
        {
            par[p.first->left->val] = p.first->val ;
            q.push({ p.first->left , p.second + 1} ) ;
        }     
        if( p.first->right )
        {
            par[p.first->right->val] = p.first->val ;
            q.push({ p.first->right , p.second + 1} ) ;
        }     
    } 
    while(!q.empty())q.pop() ;
    q.push({ A , 0 }) ;
    while( !q.empty() )
    {
        pair< TreeNode* , int >  p  = q.front();
        q.pop() ;
        if( p.second == level )
        {
            if(par[p.first->val ] != par[B] )
            {
                ans.push_back(p.first->val) ;
            } 
        }
        if( p.first->left )
        {
            // par[p.first->left->val] = p.first->val ;
            q.push({ p.first->left , p.second + 1} ) ;
        }     
        if( p.first->right )
        {
            // par[p.first->right->val] = p.first->val ;
            q.push({ p.first->right , p.second + 1} ) ;
        } 
        accumulate
    }
    return ans ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        // solve();
    }
    return 0;
}