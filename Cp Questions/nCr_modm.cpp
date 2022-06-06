#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
typedef vector<int> vi; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef map<long long, long long> mll;
typedef pair<int, int> pii;  
typedef pair<long long, long long> pll; 
typedef unsigned long long ull; 
typedef long double ld; 
typedef long long ll; 
typedef vector<vector<int>> vvi; 
typedef vector<pii> vpii; 
const int MAX_N = 1e8 + 5;

vector<long long> Factorial(MAX_N + 1, 0);
void fact_init()
{
    Factorial[0] = Factorial[1] = 1;
    for (int i = 2; i <= MAX_N; i++)
        Factorial[i] = (Factorial[i - 1] * i) % mod;
}

// returns (a^n) % mod
long long power(long long a, long long n)
{
    int64_t res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        n = n >> 1;
    }
    return res;
}

//returns (nCr) %mod
long long nCr(int n, int r)
{
    if (r > n || r < 0)
        return 0;
    if (n == r || r == 0)
        return 1; 
    // cout<<1<<"\n";
    return ((Factorial[n] * power(Factorial[r], mod - 2)) % mod * power(Factorial[n - r], mod - 2)) % mod;
}
int main()
{
    int t ;
    cin>>t ;
    fact_init() ;
    while( t-- > 0 )
    {
        int n , r ;
        cin>>n>>r ;
        cout<<Factorial[n]<<endl; 
        cout<<nCr(n,r)<<endl ;
    }
    return 0;
}