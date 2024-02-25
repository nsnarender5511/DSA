#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
//vector<int> dp(200001, -1);

/*int solve(vector<int> days, int n, int curr){
	/*cout<<cnt<<" ";
	cnt++;

	if(curr >= n) return 0;

	if(dp[curr] != -1) return dp[curr];

	int res = INT_MAX;
	for(int i=0;i<3;i++){
		if(curr+i < n){
			int ans = days[curr+i] + solve(days, n, curr+i+1);
			res = min(res, ans);
		}else{
			int ans = solve(days, n, curr+i+1);
			res = min(res, ans);	
		}
	}

	return dp[curr] = res;
}*/


/*int solve(int n, vector<int> days, vector<int> &dp){
	//cout<<cnt++<<endl;
	if(n<0) return 0;

	if(n<3) return dp[n] = days[n];
	
	if(dp[n] != -1) return dp[n];

	return dp[n] = days[n] + min({solve(n-1, days, dp), solve(n-2, days, dp), solve(n-3, days, dp)});
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	vector<int> days(n), dp(n+1, -1);
	for(int i=0;i<n;i++) cin>>days[i];
		
	int ans = 0;

	if(n==1) ans = days[0];
	else if(n==2) ans =  min(days[0], days[1]);
	else if(n==3) ans =  min({days[0], days[1], days[2]});
	else ans = min({solve(n-1, days, dp), solve(n-2, days, dp), solve(n-3, days, dp)});
	
	cout<<ans;
    return 0;
}*/



int solve(int n, vector<int>& days, vector<int>& dp){
    dp[0] = days[0];
    dp[1] = min(days[0], days[1]);
    dp[2] = min({days[0], days[1], days[2]});

    for (int i = 3; i < n; i++) {
        dp[i] = days[i] + min({dp[i-1], dp[i-2], dp[i-3]});
    }

    return min({dp[n-1], dp[n-2], dp[n-3]});
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> days(n), dp(n, 0);
    for(int i = 0; i < n; i++) cin >> days[i];
        
    int ans =  solve(n, days, dp);
    
    cout << ans;
    return 0;
}

