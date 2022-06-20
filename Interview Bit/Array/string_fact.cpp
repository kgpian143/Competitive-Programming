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
string solve(int A) {
    string ans = "1" ;
    for( int j = 2 ; j <= A ; j++ )
    {
        string temp ;
        int car = 0 ;
        for( int i = (int)ans.size() - 1 ; i >= 0 ; i-- )
        {
            int a = (ans[i] - '0')*j + car ;
            car = a/10 ;
            a = a%10 ;
            temp.push_back(a+'0');
        }
        while( car > 0 )
        {
            temp.push_back(car%10 + '0') ;
            car = car/10 ;
        }
        // cout<<temp<<" ";
        reverse( temp.begin() , temp.end()) ;
        ans = temp ;
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
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}