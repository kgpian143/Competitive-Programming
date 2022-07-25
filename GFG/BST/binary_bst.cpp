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

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
// */

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void traverse( Node *root , vector<int> &v )
    {
        if( !root )return ;
        traverse( root->left , v ) ;
        v.push_back(root->data) ;
        traverse( root->right , v) ;
    }
    void arrtobst( Node *root , vector<int> & v)
    {
         if( !root )return ;
         arrtobst( root , v );
         root->data = v.back() ;
         v.pop_back() ;
         arrtobst( root->right , v) ;
    }
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> arr ;
        traverse( root , arr ) ;
        sort(arr.begin() , arr.end());
        reverse(arr.begin() , arr.end());
        arrtobst( root , arr );
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        solve();
    }
    return 0;
}