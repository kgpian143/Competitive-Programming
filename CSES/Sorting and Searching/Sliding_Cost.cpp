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
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
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
    int n , k;
    cin>>n >> k ;
    vi v ;
    f(i,0,n)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    vi ans ;
    int sum =  0 , med;
    ordered_set st;
    int m = (k - 1)/2 ;
    for (int i = 0, j = 0; i < n; i++)
    {
        if (i < k)
        {
            st.insert(v[i]);
        }
        else 
        {
            // cout<<"rfd\n" ;
            st.erase(st.upper_bound(v[j]));
            st.insert(v[i]);
            auto it = st.find_by_order(m);
            sum += abs( *it - v[i]) - abs(med - v[j]) ;
            if( !(k & 1) )sum = sum + med - *it ;
            med = *it ;
            ans.push_back(sum);
            j++ ;
        }
        if( i == k-1 )
        {
            auto it = st.find_by_order(m) ;
            med = *it ;
            for( int j = 0 ; j < k ; j++ )
            {
                sum = sum + abs(med - v[j]) ;
            }
            ans.push_back(sum) ;
        }
    }
    for (auto it : ans)
        cout << it << " ";
    return 0;
}