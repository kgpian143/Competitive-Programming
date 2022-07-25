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
bool checkstr( string &s )
{
    int p = 0 ; 
    f( i , 0 , s.size() )
    {
        if( s[i] == '(')p++ ; 
        if( s[i] == ')')p-- ;
        if( p < 0 )return false  ; 
    }
    if( p != 0 )return false  ; 
    return true  ; 
}
void solve()
{
    string s;
    cin >> s;
    vi pos ; 
    int op = (s.size() )>> 1  , cl = (s.size())>>1  ; 
    for( int i = 0 ; i < s.size() ; i++ )
    {
        if( s[i] == '?')pos.push_back(i) ; 
        else if( s[i] == '(')op-- ; 
        else cl-- ; 
    }

    for( int i = 0 ; i < pos.size() ; i++ )
    {
        if( i < op )s[pos[i]] = '(' ; 
        else s[pos[i]] = ')' ; 
    }
    if( op > 0 && cl > 0 )
    {
        swap( s[pos[op-1]] , s[pos[op]] ) ; 
        if( checkstr(s))
        {
            cout<<"NO"<<endl ;
            return ; 
        }
    }
    cout<<"YES"<<endl ; 
    return  ; 
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