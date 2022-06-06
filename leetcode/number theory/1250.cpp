#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007
bool isGoodArray(vector<int>& nums) {
        int gcd = nums[0] ;
        for( int i = 1 ; i < nums.size() ; i++  )
        {
            gcd = __gcd( gcd ,  nums[i] ) ;
        }
        return (gcd == 1) ; 
    } 
int main()
{
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n ;
        cin>>n ;
        vector<int> v( n , 0 ) ;
        for( int i = 0 ; i  < n ; i++ )cin>>v[i] ;
        cout<<isGoodArray(v)<<endl  ;
    }
    return 0;
}