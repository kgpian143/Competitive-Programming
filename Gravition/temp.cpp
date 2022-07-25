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
bool checkstr( str)
int solve(vector<string>& A)
{
    int res = 0;
    int n = (int)A.size();
    vector<string> str ;
    for( int i = 0 ; i < n ; i++ )
    {
        if( checkstr( A[i] ))str.push_back(A[i]) ;
    }
    int k = (int)str.size() ;
    int total_subsets = 1 << k ; 
    for(int i=0;i< total_subsets ;i++)
    {
        int sum = 0,cnt = 0;
        set<char> set1;
        int tmp = i;
        for(int j=0;j<k;j++)
        {
            if(tmp&1)
            {
                for(auto it : str[j])
                {
                    set1.insert(it);
                    sum++;
                }
                cnt++;
            }
            tmp *= 2 ;
        }
       
        if(sum == (int)set1.size()&&cnt>=2)
        {
            res = max(res,sum);
        }
    }
    return res; 
    
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