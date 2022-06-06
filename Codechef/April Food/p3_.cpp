#include<bits/stdc++.h>
using namespace std ; 
int max_ele( vector<int> v  )
{
    int index = 0 ;
    int max = v[index] ;
    for( int i = 1 ; i < v.size() ; i++)
    {
        if( max <= v[i])
        {
            max = v[i] ;
            index = i ;
        }
    }
    return index ; 
}
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
        int cnt = 0 ;
        while( !v.empty())
        {
            // int index = max_element(v.begin(),v.end()) - v.begin();
            int index = max_ele(v);
            // cout<<index;
            int temp = v[index] ;
            for( int i = index ; i < v.size() - 1 ; i++ )v[i] = v[i+1] ;
            v[v.size() - 1 ] = temp ;
            cnt += v.size() - 1 - index ;
            v.erase(v.end() - 1) ;
            if( cnt > n-1)break ;
        }
        // cout<<cnt ;
        if( cnt < n-1 )cout<<"YES"<<endl ;
        else cout<<"NO"<<endl ;
    }
    return 0;
}