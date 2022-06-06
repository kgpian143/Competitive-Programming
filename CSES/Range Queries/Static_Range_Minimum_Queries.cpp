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
const int max_n = 2e5 + 5;
int table[max_n][25];
class sparsetable
{
public:  
    sparsetable(vector<int> v)
    {
        int n = v.size() - 1;
        for (int l = n  ; l > 0; l--)
        {
            for (int w = 0; w < 25; w++)
            {
                int r = l + (1 << w) - 1;
                if (r > n)
                    break;
                if (r == l)
                    table[l][w] = v[l];
                else
                    table[l][w] = min(table[l][w - 1], table[l + (1 << (w - 1))][w - 1]);
            }
        }
    }
    int query( int l , int r )
    {
        int w = r - l + 1  ;
        int pr = log2(w) ;
        return min( table[l][pr] , table[r-(1<<pr) + 1][pr]) ;
    }
};

int main()
{
    int n , q ;
    cin>>n >>q ;
    vi v ;
    v.push_back(INT_MAX);
    f( i , 1 , n+1 )
    {
        int a ;
        cin>>a ;
        v.push_back(a) ;
    }
    sparsetable spt(v) ;
    // f( i , 1 , n+1)cout<<table[i][0] ;
    while( q-- > 0 )
    {
        int l , r ;
        cin>>l>>r ;
        cout<<(spt.query(l,r))<<endl;
    }
    return 0;
}