#include <bits/stdc++.h>

using namespace std;
int cnt = 0;
vector<int> dp(10001, -1);

int solve(int n, vector<int> houses, int curr){
	//cout<<cnt++<<" ";
	if(curr == n) return 0;
	if(curr == n-1) return houses[n-1];

	if(dp[curr] != -1) return dp[curr];

	return dp[curr] = max((houses[curr] + solve(n,houses,curr+2)),  solve(n, houses, curr+1));

}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	vector<int> houses(n);
	for(int i=0;i<n;i++) cin>>houses[i];

	cout<<solve(n,houses,0);

    return 0;
}