#include <bits/stdc++.h>

#define int long long
#define mp make_pair
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

typedef long double ld;
typedef long long ll;

using namespace std;

mt19937 rnd(143);

const int inf = 1e10;
const int M = 998244353;
const ld pi = atan2(0, -1);
const ld eps = 1e-4;

signed main(){
    int n;
    cin >> n;
    int l = 1, r = n;
    int div = 0;
    while(r - l > 1){
        int mid = (r + l) / 2;
        cout << "+ "<< n - mid << endl;
        int d;
        cin >> d;
        if(d > div)l = mid;
        else r = mid;
        l = (l + n - mid) % n;
        r = (r + n - mid) % n;
        if(r == 0) r = n;
        div = d;
    }
    cout << "! " << div * n + l;
    return 0;
}