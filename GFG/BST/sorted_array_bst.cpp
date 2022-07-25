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
	Node* left, *right;
};
// */
// Your are required to complete this function
// function should return root of the modified BST
void traverse( Node *root , vector<int> &v ) 
{
    if( !root)return  ;
    traverse( root->left , v ) ;
    v.push_back(root->data ) ;
    traverse( root->right , v ) ;
}
Node *arrTobst( vector<int> v , int l  , int h ) 
{
    if( l < 0 && h >= v.size() )return ;
    if( l == h ) 
    {
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->left = temp->right = NULL ;
        temp->data = v[l] ;
    }
    int mid = ( l + h )/2  ;
    Node *temp  = (Node*)malloc(sizeof(Node));
    temp->data = v[mid] ;
    temp->left = arrTobst(v , l  , mid - 1 ) ;
    temp->right = arrTobst( v, h , mid+ 1 ) ;
    return temp ;
}
Node* buildBalancedTree(Node* root)
{
	// Code here
    vector<int> v ;
    traverse( root , v ) ;
    Node *ans = arrTobst( v , 0 , (int)v.size()-1) ;
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