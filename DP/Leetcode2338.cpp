#include <bits/stdc++.h>

using namespace std;

int mod = 10000009;
	
	int solve(int n, int maxValue, int curr, int val, vector<vector<int>> &dp){
		//cout<<cnt++<<" ";
		if(val>maxValue) return 0;

		if(curr==n) return 1;

		if(dp[val][curr] != -1) return dp[val][curr];

		int ans = solve(n, maxValue, curr+1, val, dp)%mod;

		int i=2;
		while((i*val) <= maxValue){
			ans = (ans +solve(n, maxValue, curr+1, val*i, dp)%mod);
			i++;
		}

		return dp[val][curr] = ans%mod;
	}

    int idealArrays(int n, int maxValue) {
    	int ans = 0;
    	vector<vector<int>> dp(maxValue+1, vector<int>(n+1, -1));
        for(int i=1;i<=maxValue;i++){
        	ans += ( solve(n, maxValue, 1, i, dp) % mod);
        }

        return ans % mod;
    }



int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n, maxValue;
	cin>>n>>maxValue;
	cout<<idealArrays(n,maxValue);
    return 0;
}