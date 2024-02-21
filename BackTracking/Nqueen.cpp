#include <bits/stdc++.h>

using namespace std;


bool canPlace(vector<vector<int>> board, int i, int j){
	int n = board.size();
	for(int r=0;r<n;r++){
		if(board[i][r] == 1 || board[r][j]==1){
			return false;
		}
	}

	while(i>=0 && j>=0){
		if(board[i][j]==1) return false;

		i--;
		j--;
	}

	i++;
	j++;

	while(i<n && j<n){
		if(board[i][j]==1) return false;

		i++;
		j++;
	}

	return true;
}

void printBoard(vector<vector<int>> board){

	int n = board.size();

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}

void Nqueen(vector<vector<int>> &board, int j){

	int n = board.size();

	if(j>=n){
		printBoard(board);
		return;
	}

	for(int i=0;i<n;i++){
		if(canPlace(board, i, j)){
			board[i][j] = 1;
			Nqueen(board, j+1);
			board[i][j] = 0;
		}
	}

}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	vector<vector<int>> board(4, vector<int>(4, 0));

	Nqueen(board, 0);



    return 0;
}