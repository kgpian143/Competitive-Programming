#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define f(i, a, b) for (int i = a; i < b; i++)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<vector<bool>> vvb;
typedef map<int, int> mii;
typedef map<long long, long long> mll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vi v(n , 0 );
        long long int sum = 0 ;
        f(i,0,n)
        {
            cin>>v[i];
            sum += v[i] ;
        }
        if( (sum - n/2)% n != 0 )
        {
            cout<<"NO"<<endl ;
        }
        else 
        {
            cout<<"YES"<<endl ;
        }
    }
    return 0;
}