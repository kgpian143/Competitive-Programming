/*
There's an array A consisting of N non-zero integers A1..N. A subarray of A is called alternating if any two adjacent elements in it have different signs (i.e. one of them should be negative and the other should be positive).

For each x from 1 to N, compute the length of the longest alternating subarray that starts at x - that is, a subarray Ax..y for the maximum possible y ≥ x. The length of such a subarray is y-x+1.
*/

#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n ;
        cin>>n ;
        int *A = new int[n] ;
        int *A = new int[n] ;
        for( int i = 0 ; i < n ; i++)
        {
            cin>>A[i] ;
        }
        int cnt = 0 ;
        for( int i = n-1 ; i >= 0 ; i++)
    }
    return 0;
}
