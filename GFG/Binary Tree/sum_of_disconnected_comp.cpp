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
    Node* left;
    Node* right;
};
// */

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int , int> sum( Node *root ) 
    {
        if( root == NULL )return { 0 , 0 } ;
        pair<int , int> p1 = sum( root->left) ; 
        pair<int , int> p2 = sum( root->right) ; 
        pair< int , int > ans ;
        ans.first =  root->data + p1.second + p2.second ;
        ans.second = max( p1.first , p1.second ) + max( p2.first , p2.second ) ;
        return ans ;
    }
    int getMaxSum(Node *root) 
    {
        // Add your code her
        pair<int , int > ans = sum( root );
        return max( ans.first , ans.second );
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