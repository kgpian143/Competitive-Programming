#include<bits/stdc++.h>
using namespace std ; 

int main()
{
    int t ;
    cin>>t ;
    while( t-- > 0 )
    {
        int n ;
        cin>>n ;
        vector<int> v ;
        for( int i = 0 ; i < n ; i++ )
        {
            int a ;
            cin>>a;
            v.push_back(a);
        }
        int cnt  = 0 ;
        for( int i = 0 ; i < n-1 ; i++ )
        {
            if( v[i] > v[i+1])
            {
                int temp = v[i] ;
                v[i] = v[i+1] ;
                v[i+1] = temp ;
                cnt++ ;
            }
            if( cnt > 1)break ;
        }
        if( cnt == 1)
        {
            for( int i = 0 ; i < n-1 ; i++ )
            {
                if( v[i] > v[i+1])
                {
                    cnt++ ;
                    break ;
                }
            }
        }
        // cout<<cnt ;
        if( cnt < 2 )cout<<"YES"<<endl ;
        else cout<<"NO"<<endl ;
       
    }
    return 0;
}