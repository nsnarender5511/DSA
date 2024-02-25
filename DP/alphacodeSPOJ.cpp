#include <bits/stdc++.h>

using namespace std;
int cnt = 0;

int charToInt(char c){
	return (int(c) - 48);
}

int solve(string s, int curr, vector<int> &dp){
	//cout<<cnt++<<" ";

	if(curr==s.length()) return 1;

	if(curr==s.length()-1) return 1;

	if(dp[curr] != -1) return dp[curr];

	int n = (10 * charToInt(s[curr])) + charToInt(s[curr+1]);
	
	int ans =  solve(s, curr+1, dp);

	if(n<=26) ans += solve(s, curr+2, dp);

	return dp[curr] = ans;



}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	string s;
	int ans = 0;
	while(cin>>s){
		if(s=="0") return 0;
		//cout<<s<<endl;
		cnt = 0;
		vector<int> dp(s.length()+1, -1);
		cout<<solve(s, 0, dp)<<endl;
		//ans += charToInt('1');
	}	
    return 0;
}