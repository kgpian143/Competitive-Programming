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
	int key;
	struct Node *left, *right;
};
// */

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
Node *rightchild( Node *root )
{
    if( !root->right )return root ;
    else return rightchild( root->right) ;
}
Node *leftchild( Node *root )
{
    if( !root->left )return root ;
    else return leftchild( root->left) ;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
    if( root == NULL )return ;
    if( root->key == key )
    {
        if( root->right )suc = rightchild( root->right);
        if( root->left )pre = leftchild( root->left);
        return ;
    }
    else if( root->key > key )
    {
        suc = root ;
        findPreSuc( root->left , pre , suc , key ) ;
    }
    else 
    {
        pre = root ;
        findPreSuc( root->left , pre , suc , key ) ;
    }

}
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