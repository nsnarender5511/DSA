#include <bits/stdc++.h>

using namespace std;

bool isSorted(vector<int> arr, int curr){
	if(arr.size() == curr) return true;

	if(arr[curr - 1] > arr[curr]) return false;

	return isSorted(arr, curr+1);


}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	vector<int> arr;
	int n;
	while(cin>>n) arr.push_back(n);

	(isSorted(arr, 1)) ? cout<<"TRUE " : cout<<"FALSE ";
/*
	for(int i=1;i<n;i++){
		if(arr[i-1] > arr[i]){
			cout<<"False";
			return 0;
		}
	}	
	cout<<"True";*/
    return 0;
}