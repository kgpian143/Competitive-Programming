#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'
#define sp ' '
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define debg(x) cout << "x : " << x << endl
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<vector<bool>> vvb;
typedef map<int, int> mii;
typedef map<int, int> mll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef unsigned int ull;
typedef long double ld;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
const int N = 1e5 + 5;

string getEarliestMeetTime(vector<string> events, int k)
{
    vector<pair<pair<int, int>, pair<int, int>>> tm(events.size());
    for (int i = 0; i < events.size(); i++)
    {
        string s = events[i].substr(events[i].size() - 11, 11);
        tm[i].first.first = (s[0] - '0') * 10 + s[1] - '0';
        tm[i].first.second = (s[3] - '0') * 10 + s[4] - '0';
        tm[i].second.first = (s[6] - '0') * 10 + s[7] - '0';
        tm[i].second.second = (s[9] - '0') * 10 + s[10] - '0';
    }
    sort(tm.begin(), tm.end());
    int j = 0;

    if ((tm[0].first.first * 60 + tm[0].first.second) > k)
        return "00:00";
    for (int i = 1; i < tm.size(); i++)
    {
        if (tm[i].first > tm[j].second)
        {
            int a = 60 * (tm[i].first.first - tm[j].second.first) + tm[i].first.second - tm[j].second.second;
            // debg(a) ;
            if (a > k)
            {
                tm[j].second.second += 1;
                if (tm[j].second.second > 59)
                {
                    tm[j].second.second = 0;
                    tm[j].second.first += 1;
                }
                string ans;
                ans.push_back((tm[j].second.first / 10) % 10 + '0');
                ans.push_back((tm[j].second.first) % 10 + '0');
                ans.push_back(':');
                ans.push_back((tm[j].second.second / 10) % 10 + '0');
                ans.push_back((tm[j].second.second) % 10 + '0');
                return ans ;
            }
            j = i ;
        }
        else if( tm[i].second > tm[j].second ) j = i ;
    }
    int a = 60 * (23 - tm[j].second.first) + 59 - tm[j].second.second;
    // cout << a ;
    debg(a) ;
    if (a > k)
    {
        tm[j].second.second += 1;
        if (tm[j].second.second > 59)
        {
            tm[j].second.second = 0;
            tm[j].second.first += 1;
        }
        string ans;
        ans.push_back((tm[j].second.first / 10) % 10 + '0');
        ans.push_back((tm[j].second.first) % 10 + '0');
        ans.push_back(':');
        ans.push_back((tm[j].second.second / 10) % 10 + '0');
        ans.push_back((tm[j].second.second) % 10 + '0');
        return ans;
    }
    return "-1" ;
}

void solve()
{
    int n = 2 , k = 60 ;
    // cin >> n >> k ;
    vs events =  {"a s , 00:00 11;00" , "v s 12:00 18:59"} ;
    
    string ans = getEarliestMeetTime( events , k );
    cout << ans << endl ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;
    int t = 1;
    // cin >> t;
    while (t-- > 0)
    {
        solve() ;
    }
    return 0;
}