#include<bits/stdc++.h>
using namespace std ;
#define mod 1000000007 
#define f(i,a,b) for( int i = a ; i < b ; i++ ) 
#define lb lower_bound
#define ub upper_bound 
#define all(v) v.begin() , v.end() 
typedef vector<int> vi; 
typedef vector<bool> vb; 
typedef vector<vector<int>> vvi; 
typedef vector<string> vs; 
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl; 
typedef vector<vector<bool>> vvb ;
typedef map<int, int> mii; 
typedef map<long long, long long> mll;
typedef pair<int, int> pii;  
typedef pair<int, bool> pib;  
typedef pair<long long, long long> pll; 
typedef unsigned long long ull; 
typedef long double ld; 
typedef long long ll; 
typedef vector<vector<int>> vvi; 
typedef vector<pii> vpii;
vector<int> nextGreater(vector<ll>& arr, int n) {
	stack<int> s;	
        vector<int> result(n, n);
	for (int i = 0; i < n; i++) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			result[s.top()] = i;	
			s.pop();
		}
		s.push(i);
	}
        return result;
}
 
vector<int> prevGreater(vector<ll>& arr, int n) {
	stack<int> s;	
        vector<int> result(n, -1);
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			result[s.top()] = i;	
			s.pop();
		}
		s.push(i);
	}
        return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0) ;
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        
    }
    return 0;
}