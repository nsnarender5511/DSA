//https://www.hackerrank.com/contests/w16/challenges/vim-war


#include <bits/stdc++.h>

using namespace std;
int cnt = 0;
map<string, vector<bool>> dp;

bool charToBool(char c){
	return (c=='0') ? false : true;
}

char boolToChar(bool b){
	return (b) ? '1' : '0';
}

int solve(vector<string> skills, string req, int curr, string currArmy){
	cout<<cnt++<<" ";
    if(req == currArmy && curr==skills.size()) {
    	/*for(int i=0;i<track.size();i++) cout<<track[i]<<" ";
    	cout<<endl;*/
    	return 1;
    }
    
    if(curr == skills.size()) return 0;
    
    

    int ans = 0;
    string tempArmy = "";
    for(int i=0;i<req.length();i++){
    	tempArmy += boolToChar( charToBool(skills[curr][i]) || charToBool(currArmy[i]) );
    }
    //cout<<curr<<" "<<currArmy<<" "<<tempArmy<<endl;
    //track.push_back(curr+1);
    ans += solve(skills, req, curr+1, tempArmy);
    //track.pop_back();
    ans += solve(skills, req, curr+1, currArmy);
 
    
    return ans;
    
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin>>n>>m;
	
	vector<string> skills(n);
	for(int i=0;i<n;i++){
		cin>>skills[i];
	}
	string req;
	cin>>req;
	string currArmy(m, '0');
	cout<<solve(skills, req, 0, currArmy);
    return 0;
}