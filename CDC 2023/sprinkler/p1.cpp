#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;

#define fi(n)           for(int i=0;i<n;i++)
#define fj(n)           for(int j=0;j<n;j++)
#define fk(n)           for(int k=0;k<n;k++)
#define pb                  push_back
#define ppb                 pop_back
#define pf                  push_front
#define ppf                 pop_front
#define uniq(v)             (v).erase(unique(all(v)),(v).end())
#define siz(x)               (int)((x).size())
#define ub                  upper_bound
#define lb                  lower_bound
#define bs                  binary_search
#define rep(i,a,b)          for(int i=a;i<b;i++)
#define mem1(a)             memset(a,1,sizeof(a))
#define mem0(a)             memset(a,0,sizeof(a))
#define mem(a,b)            memset(a,b,sizeof(a))
#define f                   first
#define s                   second
#define all(x)              x.begin(), x.end()
#define dbg(x)      cout << #x << " is " << x << endl;

//template <typename T>
//using ordered_set = tree<T, null_type,
//      less<T>, rb_tree_tag,
//      tree_order_statistics_node_update>;

typedef long long int           ll;
typedef long double             ld;
typedef pair<int,int>           pii;

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll MX = 9*1e18;

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

mt19937 rng (chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";}
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
 

const int nax = 1e5+5;



void solve()
{
	int n;
	cin >> n;

	vector<int> a(n), dp(nax);
	map<int,int> mp;
	for(int i=0; i<n; i++) cin >> a[i];

	// make a linear sieve
	vector<int> pr, lp(nax);
	for(int i=2; i<nax; i++){
		if(lp[i]==0){
			lp[i]=i;
			pr.pb(i);
		}
		for(int j=0; i*pr[j]<nax; j++){
			lp[i*pr[j]] = pr[j];
			if(pr[j]==lp[i]) break;
		}
	}

	// dbg(pr);

	for(int i=0; i<n; i++) {
		mp[a[i]]++;
		dp[a[i]] = mp[a[i]];
	}
	int ans=1;

	for(int i=1; i<nax; i++){
		if(dp[i]==0) continue;
		for(int j=0; i*pr[j]<nax; j++){
			amax(dp[i*pr[j]],mp[i*pr[j]]+dp[i]);
		}
		if(mp[i]!=0) amax(ans,dp[i]);
	}
    
    cout << ans;

    
    cout << "\n";
}



int main()
{
    //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int kase=1;
    // cin >> kase;
    while (kase--)
        solve();

    // cerr<< "Time taken: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}