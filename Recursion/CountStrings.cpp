/*
	COUNT THE NO OF BINARY STRINGS WITH NO CONSECETIVE ONES THAT CAN FORM USING 
	BINARY STRING OF LENGTH N
*/


  

#include <bits/stdc++.h>

using namespace std;



int solve(int n ){

	if(n==0) return 1;
	if(n==1) return 2;
	if(n==2) return 3;

	//s[curr] = 0;

	//s[curr] = 1 then s[curr+1] = 0

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