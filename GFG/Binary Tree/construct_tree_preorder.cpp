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
// *
class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int ind = lower_bound( in , in + n , pre[0] ) - in ;
        Node *temp ;
        temp = ( Node *)malloc( sizeof(Node)) ;
        temp->data = pre[0] ;
        temp->left = buildTree( in ,  pre + 1 , ind ) ;
        temp->right = buildTree( in + ind , pre + ind , n - ind - 1) ;
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