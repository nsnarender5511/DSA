#include <bits/stdc++.h>

using namespace std;

int mod = 1000000007;
int cnt = 0;



int solve(int n, vector<int> a, int acurr, int bcurr, vector<vector<int>> &dp){
	//cout<<cnt++<<" ";
	if(acurr==n){
		//res.push_back(temp);
		return 0;
	}

	if(dp[acurr][bcurr] != -1) return dp[acurr][bcurr];

	int ans = 0;
	if(a[acurr]%bcurr == 0){
		//temp.push_back(a[acurr]);
		ans = ((1 + solve(n, a, acurr+1, bcurr+1, dp)) % mod);
		
		//temp.pop_back();
	}
		
		ans += (solve(n, a, acurr+1, bcurr, dp) % mod);
	
	return  dp[acurr][bcurr] = ans;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	//vector<int> v;

	vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

	int ans = solve(n, a, 0, 1, dp);
	cout<<ans;


    return 0;
}