#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<long long, null_type, less<long long>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set; // *find_by_order

#define ll long long
#define ft first
#define sd second
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define pll pair<long long, long long>
#define vp vector<pair<long long, long long>>
#define fr(i,b,e) for(ll i=b; i<e; i++)
#define inpt(a,n) for(ll i=0; i<n; i++) cin>>a[i];
#define all(v) v.begin() , v.end()
#define en '\n'
const ll M=1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin>>n;
    ll p; cin>>p;
    ordered_set s;
    fr(i,0,n)
    {
        ll x;
        cin>>x;
        s.insert(x);
    }

    while(p--)
    {
        ll wt;
        cin>>wt;
        ll rank = s.size()-s.order_of_key(wt+1);
        cout<<(rank+1)<<en;
        s.insert(wt);
    }

    return 0;
}