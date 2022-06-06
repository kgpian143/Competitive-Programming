#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>
#define mod 1000000007
#define int long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
const int N = 2e5 + 5;
int h[N] ;
struct man
{
    int ad ;
    int ld ;
    int ind ;
};
bool comp( man x , man y )
{
    if(x.ad != y.ad)return x.ad < y.ad ;
    else if( x.ld != y.ld )return x.ld > y.ld ;
    else return x.ind > y.ind ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<man> v ;
    map<pii, int> m;
    set<pair<pii , int>> st;
    int maxroom = 1;
    f(i, 0, n)
    {
        man m1;
        cin >> m1.ad >> m1.ld;
        m1.ind = i+1 ;
        v.push_back(m1) ;
    }
    sort(all(v) , comp);
    // for(auto it : v )cout<<it.ad<<" "<<it.ld<<" "<<endl ;
    st.insert({{v[0].ld , v[0].ad } , v[0].ind});
    h[v[0].ind] = 1 ;
    set<int> room ;
    for (int i = 1; i < n; i++)
    {
        auto it = st.begin();
        if ((*it).first.first < v[i].ad)
        {
            // h[v[i].ind] = h[(*it).second] ;
            // st.erase(it);
            // st.insert({{v[i].ld , v[i].ad} , v[i].ind});
            int minr = INT_MAX ;
            while((*it).first.first < v[i].ad && st.size() > 0 )
            {
                st.erase(it);
                room.insert(h[(*it).second]) ;
                if(st.size() > 0 )it = st.begin() ;
            }
            h[v[i].ind] = *(room.begin()) ;
            room.erase(room.begin()) ;
            st.insert({{v[i].ld , v[i].ad} , v[i].ind});
        }
        else
        { 
            if( room.size() > 0 )
            {
                h[v[i].ind] = *(room.begin());
                room.erase(room.begin()) ;
                st.insert({{v[i].ld , v[i].ad} , v[i].ind}) ;  
            }
            else 
            {
            int r = (int)st.size() + 1;
            h[v[i].ind] = r;
            maxroom = max( maxroom , r);
            st.insert({{v[i].ld , v[i].ad} , v[i].ind}) ;
            }
        }
        // cout<<h[v[i].ind]<<endl;
    }
    cout << maxroom << endl;
    for (int i = 0; i < n; i++)
    {
        cout << h[i+1] << " ";
    }
    return 0;
}