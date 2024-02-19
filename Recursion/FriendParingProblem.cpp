#include <bits/stdc++.h>

using namespace std;


int solve(int n){
	if(n==1) return 1;
	if(n==2) return 2;

	return solve(n-1) + solve(n-2);
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