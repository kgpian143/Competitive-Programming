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

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// */
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void traverse( Node *root , vector<int> &v ) 
    {
        if( !root )return  ;
        traverse( root->left , v )  ;
        v.push_back(root->data) ;
        traverse( root->right , v ) ;  
    }
    void merge_vec( vector<int> &v1 , vector<int> &v2 , vector<int> &ans ) 
    {
        int i = 0 , j = 0 ;
        while( i < v1.size() && j < v2.size() )
        {
            if( v1[i] < v2[j] )ans.push_back(v1[i++]) ;
            else ans.push_back(v2[j++]) ;
        }
        while( i < v1.size() )ans.push_back(v1[i++]) ;
        while( j < v2.size() )ans.push_back(v2[j++]) ;
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> v1 , v2 , ans ;
       traverse(root1 , v1) ;
       traverse( root2 , v2 ) ;

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