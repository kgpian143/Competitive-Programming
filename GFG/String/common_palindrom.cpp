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
#define getv(v,n) for( int i = 0 ; i < n ; i++)cin>>v[i];
#define putv(v) for(auto it : v )cout<<it<<' ';
#define getvv(v,n,m)for(int i = 0 ; i < n ; i++ )f(j,0 ,m)cin>>v[i][j] 
const int N = 2e5 + 5; 

 string lookandsay(int n) {
        // code here
        string ans = "1";
        string temp = ans  ;
        for( int i = 2 ; i <= n ; i++)
        {
            temp = ans ;
            ans.clear() ;
            // cout<<temp<<" ";
            int j = 1 ;
            int cnt = 1 ;
            while( j < temp.size() )
            {
                if( temp[j] == temp[j-1])cnt++ ;
                else 
                {
                    ans.push_back('0' + cnt );
                    ans.push_back(temp[j-1]) ;
                    cnt = 1 ;
                }
                j++ ;
            }
            ans.push_back('0' + cnt);
            ans.push_back(temp.back());
        }
        return ans ;
 }
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n ;
        cin>>n ;
        cout<<lookandsay(n)<<endl;
    }
    return 0;
}