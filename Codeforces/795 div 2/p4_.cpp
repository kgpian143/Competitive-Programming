#include<bits/stdc++.h>
using namespace std;

main(){
	int t;
	cin >> t;
	for(int _ = 0; _ < t; _++){
		int n;
		cin >> n;
		string ans = "YES\n";
		int mx = -1e9-7, tot = 0, a[n];
		for(int i = 0; i < n; i++)cin >> a[i];
		for(int i = 0; i < n; i++){
			tot += a[i];
			mx = max(a[i], mx);
			if(tot > mx)ans = "NO\n";
			if(tot < 0){
				tot = 0;
				mx = -1e9-7;
			}
		}
		tot = 0; mx = -1e9-7;
		for(int i = n-1; i >= 0; i--){
			tot += a[i];
			mx = max(a[i], mx);
			if(tot > mx)ans = "NO\n";
			if(tot < 0){
				tot = 0;
				mx = -1e9-7;
			}
		}
		cout << ans;
	}
}