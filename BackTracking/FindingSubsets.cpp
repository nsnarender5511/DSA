#include <bits/stdc++.h>

using namespace std;


void subsets(string S, int curr, string temp){
	if(curr==S.length()){
		cout<<temp<<endl;
		return;
	}

	subsets(S, curr+1, temp);

	temp += S[curr];

	subsets(S, curr+1, temp);

}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	subsets("abc", 0, "");

    return 0;
}