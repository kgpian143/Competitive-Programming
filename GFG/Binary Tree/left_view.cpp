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
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans ;
   stack<pair< Node* , int > > st  ;
   int max_level = 0 ;
   st.push({ root , 1 } ) ;
   while( !st.empty())
   {
       pair< Node* , int > p = st.top() ;
       st.pop() ;
       if( p.second > max_level )
       {
          max_level = p.second ;
          ans.push_back( p.first->data ) ;
       }
       if( p.first->left != NULL )
       {
           st.push({ p.first->left , p.second + 1 }) ;
       }
       if( p.first->right != NULL )
       {
           st.push({ p.first->right , p.second + 1 }) ;
       }
   }
   return ans  ;
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