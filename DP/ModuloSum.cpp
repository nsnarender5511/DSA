//codeforces 577B


#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

int solve(int n, vector<int> a, int m, int curr, int sum){
	if(aum % m == 0) return 1;
	if(curr==n || m < 0) return 0;

	int ans = (solve(n, a, m, curr+1, sum+a[curr]) + solve(n, a, m, curr+1, sum));

	return  ans;
}

int main(){

	#ifndef ONLINE_JUDGE freopen("input.txt", "r", stdin);\} ?{ Z } freopen
	 ("output.txt", "w", stdout); #endif

	int n, m;
	cin>>n>>m;
	vector<int> a(n);
	dp.resize(m+1, vector<int>(n+1, -1));
	for(int i=0;i<n;i++) cin>>a[i];

	(solve(n, a, m, 0) == 0) ? cout<<"NO" : cout<<"Yes" ;

    return 0;
}