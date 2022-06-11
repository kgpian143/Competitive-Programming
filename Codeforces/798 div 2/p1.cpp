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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n , m , k  ;
        cin>>n>>m>>k;
        string s1 ,  s2 ;
        cin>>s1>>s2 ;
        sort(all(s1)) ;
        sort(all(s2)) ;
        int prev = 0 , cnt = 0;
        int i = 0 , j = 0 ;
        string c ;
        while( i < s1.size() && j < s2.size()  )
        {

            if(s1[i] < s2[j]) 
            {
                if( prev == 1 && cnt == k )
                {
                    c.push_back(s2[j++]) ;
                    cnt = 1 ;
                    prev = 2 ;
                }
                else if( prev == 2 )
                {
                    c.push_back(s1[i++]) ;
                    cnt = 1 ;
                    prev = 1 ; 
                }
                else 
                {
                    c.push_back(s1[i++]) ;
                    cnt++ ;
                    prev = 1 ;
                }
            }
            else 
            {
                if( prev == 2 && cnt == k )
                {
                    c.push_back(s1[i++]) ;
                    cnt = 1 ;
                    prev = 1 ;
                }
                else if( prev == 1 )
                {
                    c.push_back(s2[j++]) ;
                    cnt = 1 ;
                    prev = 2; 
                }
                else 
                {
                    c.push_back(s2[j++]) ;
                    cnt++ ;
                    prev = 2 ;
                }
            }
        } 
        cout<<c<<endl;
    }
    return 0;
}