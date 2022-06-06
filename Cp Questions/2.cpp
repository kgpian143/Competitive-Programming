#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while( t-- > 0 )
    {
        map<int,int> m;
        int n , k , x;
        cin >> n >> k ;
        for( int i = 0 ; i < n ; i++ )
        {
            cin >> x ;
            m[-x]++;
        }
        auto it = m.begin() ;
        int cnt = 0 ;
        for( int i = 0 ; i < k ; i++)
        {
            cnt += it->second ;
            // cout << it->first << " " <<it->second<<endl;
            it++;
            if( cnt >= k )break;
        } 
        cout << cnt <<endl;
    } 
    return 0;
}