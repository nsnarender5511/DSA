#include <bits/stdc++.h>

using namespace std;

map<int, int> nums, cnt;
int n = 6;


bool isAutoBiographical(){
	for(int i=0;i<n;i++){
		if(nums[i]!=cnt[i]) return false;
	}

	return true;

}

void generateAutoBiographical(int index){
	if(index==n){
		if(isAutoBiographical()){
			cout<<"AutoBiographical : ";
			for(int i=0;i<n;i++){
				cout<<nums[i];
			}
			cout<<endl;
		}

		return;
	}


	for(int i=0;i<n;i++){
		nums[index] = i;
		cnt[i]++;

		generateAutoBiographical(index+1);

		nums[index] = -1;
		cnt[i]--;
	}

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	generateAutoBiographical(0);

    return 0;
}