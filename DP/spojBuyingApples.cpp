#include <bits/stdc++.h>

using namespace std;


int solve(int n, vector<int> price, vector<int> &dp){
	if(n==0) return 0;

	if(dp[n] != -2) return dp[n];
	int ans = price[n];
	for(int i=1;i<n;i++){
		if(price[i]!=-1 && price[n-1-i]!=-1)
			ans = max(ans , solve(i, price, dp) + solve(n-1-i, price, dp));
	}
	return dp[n] = ans;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int T;
	cin>>T;
	while(T--){
		int n, k;
		cin>>n>>k;
		vector<int> price(k);
		for(int i=0;i<k;i++){
			cin>>price[i];
		}
		vector<int> dp(k+1, -2);
		(k==1) ? cout<<price[0]<<endl : cout<<solve(k-1, price, dp)<<endl;
	}
    return 0;
}