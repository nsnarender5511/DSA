//https://atcoder.jp/contests/dp/tasks/dp_a


#include <bits/stdc++.h>

using namespace std;



/*int solve(vector<int> height, int n, int curr){
	//if reached last;
	//cout<<"solve(height, n, curr)  --- "<<curr<<endl;
	if(curr>=(n-1)) return 0;
	
		int cost  = abs(height[curr+1] - height[curr]) + solve(height, n, curr+1);
		int cost2 =  abs(height[curr+2] - height[curr]) + solve(height, n, curr+2);
		//cout<<curr<<" "<<i<<" "<<cost<<endl;
		
		return  min(cost, cost2);

}*/


/*int solve(vector<int> height, vector<int> &dp,int n){
	//cout<<n<<" ";
	if(n==0) return 0;
	if(n==1) return abs(height[1] - height[0]);

	if(dp[n] != -1) return dp[n];

	dp[n] = min((abs(height[n] - height[n-1]) + solve(height,dp,n-1)), (abs(height[n] - height[n-2]) + solve(height,dp, n-2)));

	return dp[n];

}*/

int solve(vector<int> &height, vector<int> &dp, int n) {
    if (n == 0) return 0;
    if (n == 1) return abs(height[1] - height[0]);

    if (dp[n] != -1) return dp[n];

    // Ensure not to go beyond vector bounds
    if (n - 1 >= 0) {
        dp[n] = abs(height[n] - height[n - 1]) + solve(height, dp, n - 1);
    }

    if (n - 2 >= 0) {
        dp[n] = min(dp[n], abs(height[n] - height[n - 2]) + solve(height, dp, n - 2));
    }

    return dp[n];
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> height(n);

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        height[i] = temp;
    }

    vector<int> dp(n, -1);

    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]);

    cout << solve(height, dp, n - 1) << endl;

    return 0;
}
