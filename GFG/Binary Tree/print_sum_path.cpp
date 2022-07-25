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
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// */
class Solution{
  public:
    void traverse( Node *root , vector<int> &v) 
    {
        if( root == NULL )return  ;
        v.push_back( root->data) ;
        traverse( root->left , v ) ;
        traverse( root->right , v ) ;
        v.push_back(-root->data) ;
    }
    int subarraySum(vector<int>& nums, int k) {
        
        //For fast I/O in C++
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        if(n==0)
            return 0;
        
        unordered_map<int,int> mymap;   //Key = PrefixSUM, Value = Count of PrefixSUM.
        int currSUM = 0;
        int i = 0;
        int cnt = 0;
        
        while(i<n)
        {
            currSUM += nums[i];
            
            if(currSUM == k)    //We found a new subArray with SUM = k
                cnt += 1;
            
            if(mymap.find(currSUM-k)!=mymap.end())
                cnt += mymap[currSUM-k];
            
            mymap[currSUM] += 1;
            i += 1;
        }
        return cnt;
    }
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> arr ;
        traverse( root , arr ) ;
        int ans  =  subarraySum( arr , k ) ;
        return ans ;
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