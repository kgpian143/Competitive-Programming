#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int t ;
    cin>>t ;
    while( t-- > 0 )
    {
        int n , mth , mth1 , mtm , mtm1 ;
        string mtst ,  mtst1 ;
        char  dummy;
        cin>>mth>>dummy>>mtm>>mtst;
        pair<int,int> mtime ;
        int a  , b;
        if( mtst == "AM")
        {
            if( mth == 12  )a = 0 ;
            else a = mth ;
            b = mtm ;
        }
        else 
        {
           if( mth ==  12)a = 12 ;
           else a = 12+mth ;
        }
        mtime = make_pair(a,b);
        cin>>n ;
        vector<pair<int,int>> sttime;
        vector<pair<int,int>> endtime;
        for( int i = 0 ; i < n ; i++ )
        {
            cin>>mth>>dummy>>mtm>>mtst>>mth1>>dummy>>mtm1;
   
        }
    }
    return 0;
} 