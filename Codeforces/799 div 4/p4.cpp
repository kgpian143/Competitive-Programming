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
int num = 1440;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<int> pali;
    // int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i == 2 && j == 4)
                break;
            int a = 60 * (10 * i + j) + 10 * j + i;
            pali.insert(a);
        }
    }
    // for( int i = 0 ; i < k ; i++ )cout<<pali[i] << " ";
    // cout<<endl; 
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string s;
        int x;
        cin >> s >> x;
        int cnt = 0;
        int time = 60 * (10 * (s[0] - '0') + s[1] - '0') + 10 * (s[3] - '0') + s[4] - '0';
        // cout<<time<<endl;
        int k = time ;
        if( pali.find(time) != pali.end() )cnt++ ;
        while(( k + x ) % num != time  )
        {
            k = ( k + x) % num ;
            if( pali.find(k) != pali.end() )cnt++ ;
        }
        // if( pali.find( 671) != pali.end() )cout<<3;
        cout << cnt << endl;
    }
    return 0;
}