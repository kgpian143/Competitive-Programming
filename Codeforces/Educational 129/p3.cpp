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

int main()
{
    int t ;
    cin>>t ;
    while(t-- > 0 )
    {
        int n ;
        cin>>n ;
        vi v(n+1 , 0 ) ;
        f( i , 1 , n+1)cin>>v[i] ;
        vi v1(n+1 , 0 ) ;
        f( i , 1 , n+1)cin>>v1[i] ;
        vi v_sort = v ;
        sort( v_sort.begin() , v_sort.end()) ;
        vi v1_sort = v1 ;
        sort( v1_sort.begin() , v1_sort.end()) ;
        vpii moves ;
        int cnt = 0 ;
        for( int i = 1 ; i <= n ; i++ )
        {
            int k = v_sort[i] ;
            int k1 = v1_sort[i] ;
            int flag = 0 ;
            for( int j = i ; j <= n ; j++)
            {
                if(k == v[j] && k1 == v1[j])
                {
                    swap(v[i] , v[j]) ;
                    swap(v1[i] , v1[j]) ;
                    if( i != j )
                    {
                        moves.push_back({i,j}) ;
                    }
                    flag++ ;
                    break ;
                }
            }
            if( flag == 0 )
            {
                cnt++ ;
                break ;
            }
        }
        if( cnt != 0 )
        {
            cout<<-1<<endl;
        }
        else 
        {
            cout<<moves.size()<<endl;
            for( int i = 0 ;  i < moves.size() ; i++ )
            {
                cout<<moves[i].first<<" "<<moves[i].second<<endl;
            }
        }
    }
    return 0;
}