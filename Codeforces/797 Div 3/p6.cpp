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
int lcm ( int a , int b )
{
    return (a*b)/__gcd(a,b) ;
}
int find(string s){
	for(int i=1 , same = 1 ; i<=s.size() ; i++ , same = 1){
		if(s.size() % i) continue ;
		for(int j=0 ; j<s.size() ; j+=i) if(s.substr(j , i) != s.substr(0 , i)) same = 0 ;
		if(same) return i ; 
	}
    return s.size() ;
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
        string s ;
        cin>>s ;
        vvi cc;
        vi v(n) ,  ans , child(n , 0);
        vb vis(n ,false) ;
        f(i,0,n)
        {
            cin>>v[i] ;
            child[i] = v[i] - 1;
        }
        // for( int i = 0 ; i < n ; i++ )cout<<i<< " "<< child[i] <<endl;
        for( int i = 0 ; i < n ; i++ )
        {
            if(vis[i])continue; 
            // vi temp; 
            // cout<<i<<endl;
            int j = i ;
            string s1 ;
            s1.push_back(s[j]) ;
            vis[i] = true ;
            j = child[j] ;
            while( j != i )
            {
                vis[j] = true ;
                s1.push_back(s[j]) ;
                j = child[j] ;
            }
            // cout<<s1<<endl;
            ans.push_back(find(s1)) ; 
        }
        // for(auto it : ans )cout<<it<<" ";
        // cout<<endl;
        int l1 = ans[0] ;
        for( int i = 1 ; i < ans.size() ; i++)
        {
            l1 = lcm(l1, ans[i]) ;
        }
        cout<<l1<<endl;
    }
    return 0;
}