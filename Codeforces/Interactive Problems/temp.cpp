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
int fact[N] ;
#define MAX_CHAR 256 
void populateAndIncreaseCount(int* count, char* str)
{
    int i;
  
    for (i = 0; str[i]; ++i)
        ++count[str[i]];
  
    for (i = 1; i < MAX_CHAR; ++i)
        count[i] += count[i - 1];
}

void updatecount(int* count, char ch)
{
    int i;
    for (i = ch; i < MAX_CHAR; ++i)
        --count[i];
}

int findRank(char* str)
{
    fact[0]= fact[1] = 1  ;
    for( int i = 2 ; i < N ; i++ )
    {
       fact[i] = (fact[i-1]*1LL*i)%mod ;
    }
    int len = strlen(str);
    int mul = fact[len];
    int rank = 1, i;
    int count[MAX_CHAR] = { 0 };
    populateAndIncreaseCount(count, str);
    for (i = 0; i < len; ++i) {
        mul /= len - i;
        rank += count[str[i] - 1] * mul;
        updatecount(count, str[i]);
    }
    return rank;
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