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
    Node* left, * right;
}; 

void traverse( Node *node , map< int , vector<int> > &m , int d )
{
    if( node == NULL)return ;
    m[d].push_back(node->data) ;
    traverse( node->left , m , d+1 ) ;
    traverse( node->right , m , d ) ;
}

vector<int> diagonal(Node *root)
{
   // your code here
    map< int , vector<int> > m ;
    vector<int> ans ;
    traverse( root , m  , 1 ) ;
    for( auto it : m )
    {
        for( auto it1 : it.second )
        {
            ans.push_back(it1) ;
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
        solve();
    }
    return 0;
}