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

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
// */
class Solution
{
public:
    int height( Node *node )
    {
        if( node == NULL )return 0 ;
        else return 1 + max( height( node->left ) , height( node->right)) ;
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        if( root ==NULL)return 0 ;
        int max_level = 0 , sum = 0 ;
        // stack<Node * , pair<int , int >> st ;
        int sum1 = ( root->left ) ? sumOfLongRootToLeafPath( root->left ) : 0 ;
        int sum2 = ( root->right ) ? sumOfLongRootToLeafPath( root->right ) : 0 ;
        int h1 = height( root->left ) ;
        int h2 = height( root->right) ;
        if( h1 == h2 )
        {
            return root->data + max( sum1 , sum2 );
        }
        else if( h1 > h2 )
        {
            return root->data + sum1 ;
        }
        else 
        {
            return root->data + sum2 ;
        }
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