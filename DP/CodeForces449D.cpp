#include <bits/stdc++.h>

using namespace std;
int cnt = 0;

/*int solve(int n, vector<int> nums, int curr, int sol,vector<vector<int>> &dp){
	//cout<<cnt++<<" ";
	if(curr==n && sol==0) return 1;

	if(curr==n) return 0;

	//cout<<curr<<"  --  "<<sol<<"  --  "<<int(sol & nums[curr])<<endl;
	if(dp[curr][sol] != -1) return dp[curr][sol];

	int ans = solve(n, nums, curr+1, sol&nums[curr], dp) 
				+ solve(n, nums, curr+1, sol, dp);

	return dp[curr][sol] = ans;


}*/


/*int solve(int n, vector<int> nums, int sol) {
    vector<vector<int>> dp(n + 1, vector<int>(sol + 1, 0));

    dp[0][0] = 1;

    for (int curr = 1; curr <= n; ++curr) {
        for (int currSol = 0; currSol <= sol; ++currSol) {
            dp[curr][currSol] = dp[curr - 1][currSol] + dp[curr - 1][currSol & nums[curr - 1]];
        }
    }

    return dp[n][sol];
}*/




int solve(int n, vector<int> nums, int sol) {
    vector<vector<int>> dp(n + 1, vector<int>(1 << 10, -1));

    function<int(int, int)> dfs = [&](int curr, int currSol) -> int {
        if (curr == n) {
            return (currSol == sol) ? 1 : 0;
        }

        if (dp[curr][currSol] != -1) {
            return dp[curr][currSol];
        }

        int ans = dfs(curr + 1, currSol & nums[curr]) + dfs(curr + 1, currSol);
        return dp[curr][currSol] = ans;
    };

    return dfs(0, 0);
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++) cin>>nums[i];
	int sol = pow(2, 20) - 1;

	//vector<vector<int>> dp(n+1, vector<int>(sol+1, -1));

	cout<<solve(n, nums, sol);

    return 0;
}