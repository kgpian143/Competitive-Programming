#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            a[i] = x; 
        }
       map<int, int> mp;

       for(int i=0; i<n; i++)
       {
           mp[a[i]]++;
       }
       int sum = 0;
       for(auto i: mp)
       {
           if(i.second >= 2)sum += 2;
           else sum += i.second;
       }
       
        cout<<(sum+1)/2<<endl;
    }
    return 0;
}