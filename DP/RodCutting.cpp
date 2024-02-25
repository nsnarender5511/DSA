#include <bits/stdc++.h>

using namespace std;
int cnt = 0;
vector<int> dp(10001, -1);

int solve(int n, vector<int> cost){
	//cout<<cnt++<<" ";
	if(n==0) return 0;

	if(dp[n] != -1) return dp[n];

	int ans = cost[n];
	for(int i=0;i<n;i++){
		ans = max(ans, solve(i, cost) + solve(n-i-1, cost));
	}
	return dp[n] = ans;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	vector<int> cost(n);
	for(int i=0;i<n;i++) cin>>cost[i];


	cout<<solve(n, cost);


    return 0;
}