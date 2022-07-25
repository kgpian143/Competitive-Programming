#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<vector<bool>> vvb;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<pii> vpii;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define mod 1000000007
#define f(i, a, b) for (int i = a; i < b; i++)
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
const int N = 2e5 + 5;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi v(n, 0);
    int cnt = 0;
    for (int i = 0; i < n - 1 ; i++)
    {
        if( cnt == k )
        {
            if( k % 2 == 0 )break;
            for( int j = i ; j < n - 1 ; j++)
            {
               if( k & 1 ) s[j] = (1 ^ ( s[j] - '0' )) + '0' ;
            }
            break ; 
        }
        if ((k & 1))
        {
            if (s[i] == '1')
            {
                v[i] = 1;
                cnt++;
            }
            else s[i] = '1' ;
        }
        else 
        {
            if( s[i] == '0' )
            {
                v[i] = 1  ;
                cnt++ ;
                s[i] = '1'  ; 
            }
        }
    }
    if( (cnt & 1)  )
    {
        if( s[n-1] == '0')s[n-1] = '1' ; 
        else s[n-1] = '0' ;
    }
    v[n-1] = k - cnt  ; 
    cout<<s<<endl; 
    for( auto it : v )cout<<it<<" ";
    cout<<endl ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
    return 0;
}