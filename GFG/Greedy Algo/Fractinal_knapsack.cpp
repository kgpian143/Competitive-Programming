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
struct Item{
    int value;
    int weight;
};


bool comp ( Item i1 , Item i2 )
{
    return (i1.value * i2.weight ) > i2.value * i1.weight ;
}
double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort( arr , arr + n , comp ) ;
        f( i ,  0 , n )cout<<arr[i].value << " "<< arr[i].weight<<endl;
        int wgt = 0 ;
        double max_profit = 0 ;
        for( int i = 0  ; i < n ; i++ )
        {
            if( wgt + arr[i].weight <=  W  )max_profit += arr[i].value ;
            else 
            {
                max_profit += ((W - wgt )/( 1.0 * arr[i].weight)) * arr[i].value ;
                break ;
            }
            wgt += arr[i].weight ;
        }
        return max_profit ;
    }
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n , w ;
        cin>>n>>w ;
        Item it[n] ;
        f( i , 0 , n )
        {
            cin>>it[i].value >> it[i].weight ;
        }
        double ans = fractionalKnapsack( w , it , n ) ;
        cout<<ans<<endl;
    }
    return 0;
}