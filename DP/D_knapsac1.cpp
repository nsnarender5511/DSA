#include <bits/stdc++.h>
#define vi vector<int>


using namespace std;

int solve(int n, int W, vi w, vi v){
	cout<<"W  --  "<<W<<endl;
	//Base Case
	if(W < w[0]){
		return 0;
	}
	int ans = 0;
	for(int i=n-1;i>=0;i--){
		if(W >= w[i]){
			cout<<"W-w[i]  --  "<<W-w[i]<<endl;
			ans = max (ans, v[i] + solve(n, (W-w[i]), w, v));
		}
	}
	cout<<ans<<"  --  "<<ans<<endl;
	return ans;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n,W;
	cin>>n>>W;
	vector<int> w(n),v(n);

	for(int i=0;i<n;i++){
		cin>>w[i]>>v[i];
		//cout<<w[i]<<" "<<v[i]<<endl;
	}

	cout<<solve(n, W, w, v)<<endl;


    return 0;
}