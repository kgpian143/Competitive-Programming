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
#define all(a) a.begin() , a.end()

vector<vector<int>> subsets(vector<int>& nums) {
        int a  = (1 << nums.size())   ;
        vvi subsets_ ;
        for( int i = 0 ; i < a ; i++ )
        {
            vi set ;
            for( int j = 0 ; j < nums.size() ; j++ )
            {
                if( i & 1 << j != 0)set.push_back(nums[j]);
            }
            if(find(all(subsets_) , set) != subsets_.end() ) subsets_.push_back(set);
        }
        return subsets_ ;
}
int main()
{
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n ;
        cin>>n ;
        int a = 1 << n ;
        vi nums( a + 1 , 0 ) ;
        for( int i = 0 ; i < a ; i++ )cin>>nums[i] ;
        
    }
    return 0;
}