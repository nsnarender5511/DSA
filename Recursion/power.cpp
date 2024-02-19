#include <bits/stdc++.h>

using namespace std;

int power(int x, int n){
	if (n==1) return x;
	if(n==0) return 1;

	return x * power(x, n-1);
}
 
int fastPower(int x, int n ){
	if (n==0) return 1;

	int subprob = fastPower(x, n/2);
	int subProbSq = subprob * subprob;

	if(n&1) return(x * subProbSq); 

	return subProbSq;  

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    
    int x,n;
    cin>>x>>n;

    cout<<fastPower(x,n);


    return 0;
}