// n+1 Disks and 3  towers 



#include <bits/stdc++.h>

using namespace std;


int noOfSteps(int n){
	if(n==1) return 1;

	return 1+(noOfSteps(n-1)*2);
}

void fullPath(int n, char from, char helper, char to){
	if(n==0) return;

	fullPath(n-1, from, to, helper);

	cout<<from<<" -->>  "<<to<<endl;

	fullPath(n-1, helper, from, to);
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	cout<<"Total Steps Required  ::  "<<noOfSteps(n)<<endl<<endl;
	fullPath(n, 'A', 'B', 'C');

    return 0;
}