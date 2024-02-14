#include <bits/stdc++.h>

using namespace std;

int fib(int n){
	if(n==1) return 0;
	if(n==2) return 1;


	return fib(n-1) + fib(n-2);
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;	
	cin>>n;
	cout<<fib(n);

    return 0;
}