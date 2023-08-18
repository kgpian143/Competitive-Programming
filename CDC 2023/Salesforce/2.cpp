#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<int> vl;
typedef vector<vector<int>> vvl;
typedef vector<vector<bool>> vvb;
typedef map<int, int> mii;
typedef map<int, int> mll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef pair<int, int> pll;
typedef unsigned int ull;
typedef long double ld;
typedef int ll;
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;
const int N = 1e5 + 5;

bool helpKitty(string s, vector<string> wordDict)
{

    set<string> st;
    for (auto it : wordDict)
        st.insert(it);
    if (st.size() == 0)
        return false;

    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (dp[j])
            {
                string word = s.substr(j, i - j);
                if (st.find(word) != st.end())
                {
                    dp[i] = true;
                    break; // next i
                }
            }
        }
    }

    return dp[s.size()];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n ;
        string s ; 
        cin >> s ;
        cin >> n ;
        vector<string> dict( n , "") ;
        
        for( int i = 0 ; i < n ; i++)
        {
            cin >> dict[i] ;
        }
        cout << helpKitty( s , dict ) << endl ;
    }
    return 0;
}