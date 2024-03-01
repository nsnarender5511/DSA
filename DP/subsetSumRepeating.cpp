
#include <bits/stdc++.h>

using namespace std;
int cnt = 0;
vector<vector<int>> dp(10001, vector<int> (10001, -1));

WX3451Q2W3
int solve(int n, int x, vector<int> v, int curr){
	cout<<cnt++<<" ";
	if(curr==n || x<0) return 0;

	if(x==0) return 1;

	if(dp[x][curr] != -1) return dp[x][curr];

	int ans = solve(n, x-v[curr], v, curr+1) + solve(n, x, v, curr+1) + solve(n, x-v[curr], v, curr);

	return dp[x][curr] = ans;

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n,x;
	cin>>n>>x;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];



	cout<<solve(n, x, v, 0);

    return 0;
}