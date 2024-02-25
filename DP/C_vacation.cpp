#include <bits/stdc++.h>

using namespace std;


/*int solve(int n,vector<int> a,vector<int> b,vector<int> c,int &count,int curr,int prev){
	if(currr==n) return;

	if(prev == -1){
		solve(n, a, b, c, count += a[curr] , curr+1 , prev = 1)
		solve(n, a, b, c, count += b[curr] , curr+1 , prev = 2)
		solve(n, a, b, c, count += c[curr] , curr+1 , prev = 3)
	}else if(prev == 1)
				solve(n, a, b, c, count += b[curr] , curr+1 , prev = 2)
				solve(n, a, b, c, count += c[curr] , curr+1 , prev = 3)

}*/
vector<int> dp(10001);
int gPoints = 0;


int solve(int n, vector<vector<int>> grid, int curr, int prev, int points){
	if(curr == n) return 0;

	
	for(int i=0;i<3;i++){
		if(prev!=i){
			gPoints = max(gPoints , solve(n, grid, curr+1, i, points + grid[curr][i]));
		}


	}

	return points;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	vector<vector<int>> grid(n, vector<int>(3));
	//vector<map<char, vector<int>>> grid;
	for(int i=0;i<n;i++){
		cin>>grid[i][0]>>grid[i][1]>>grid[i][2];
		//cout<<a[i]<<b[i]<<c[i];

		//cin>>grid[i]['a'][0];
	}
/*
	solve(n, a, b, c, count, curr, prev);*/

	cout<<solve(n, grid, 0, -1);
	//cout<<points;

    return 0;
}