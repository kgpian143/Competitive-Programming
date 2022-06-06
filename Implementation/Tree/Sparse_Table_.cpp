#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
const int  max_n = 1e5 ;
int table[max_n][25] ;
class sparsetable
{
public:
    // // vvi table( (int)max_n , vi( (int)25 , 0  )) ;
    // vi v( 25 , 0) ;
    // int **table = new int*[max_n] ;
    sparsetable(vector<int> v)
    {
        int n = v.size();
        for (int l = n - 1; l >= 0; l--)
        {
            for (int w = 0; w < 25; w++)
            {
                int r = l + (1 << w) - 1;
                if (r >= n)
                    break;
                if (w == 0)
                    table[l][w] = v[l];
                else
                    table[l][w] = min(table[l][w - 1], table[l + (1 << (w - 1))][w - 1]);
            }
        }
    }
    int query( int l , int r )
    {
        int w = l - r ;
        int pr = log2(l-r) ;
        return min( table[l][1<<pr] , table[r-(1<<pr)][1<<pr]) ;
    }
};
 int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
    }
    return 0;
}