#include <bits/stdc++.h>

using namespace std;

/*void generateParanthesis(string s, int curr, stack<char> &st){
	cout<<curr<<" "<<s<<endl;
	int n = s.length();
	if(n>=curr){
		//cout<<s<<endl;
		if(st.empty()){
			cout<<s<<endl;
		}
		return;
	}
	st.push('(');
	s[curr] = '(';
	generateParanthesis(s, curr+1, st);
	//st.pop();
	

	if(!st.empty() && st.top() == '('){
		curr += 1;
		st.pop();
		s[curr] = ')';
		generateParanthesis(s, curr+1, st);
	}




}*/

void generateParanthesis(string s, int curr, int opening, int closing, int n){
	if(curr == 2*n){
		cout<<s<<endl;
		return;
	}
	

	//opening
	if(opening < n){
		generateParanthesis(s + '(', curr+1, opening+1, closing, n);
	}


	//closing
	if(closing < opening){
		generateParanthesis(s + ')', curr+1, opening, closing+1, n);

	}

}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	string s;;
	//string s = "__";
	generateParanthesis(s, 0, 0, 0, n);
    return 0;
}