/*
	You have to go from n --> 1 with minimum steps, in one step you can do
		1. n --> n-1
		2. n --> n/2
		3. n --> n/3 
*/

#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
vector<int> dp(100001, -1);

int solve(int n){
	cout<<cnt++<<" ";
	if(n==1) return 0;

	if(dp[n] != -1) return dp[n];

	int ans = INT_MAX;
	ans = min( 1 + solve(n-1), ans);

	if(n%2==0) ans = min(1 + solve(n/2), ans);

	if(n%3 == 0) ans = min(1 + solve(n/3), ans);

	return dp[n] = ans;




}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	cout<<solve(n);


    return 0;
}