#include <bits/stdc++.h>

using namespace std;

    bool checkRow(vector<vector<char>> sudoku, int i, char val){
        int sum = 0;
        for(int j=0;j<9;j++){
            if(sudoku[i][j] == val){
                return false;
            }
        }

        return true;
    }

    bool checkCol(vector<vector<char>> sudoku, int j, int val){

        int sum = 0;
        for(int i=0;i<9;i++){
            sum += sudoku[i][j];
            if(sudoku[i][j] == val){
                return false;
            }
        }

        return true;      
	}

    bool checkGrid(vector<vector<char>> sudoku, int i, int j, char val){
        int starti = i/3, startj = j/3, sum = 0;

        for(int row=starti;row<(3 + starti);row++) {
            for(int col=startj;col<(3 + startj);col++) {

                if(sudoku[row][col] == val){
                    return false;
                }

            }
        }

        return true;
    }


    void solve(vector<vector<char>> &sudoku, int i, int j){
        if(i==9 && j==9){
            return;
        }

        if(i==9){
            solve(sudoku, 0, j+1);
        }

        if(sudoku[i][j]=='.'){

            for(int k=1;k<=9;k++){
                cout<<char(k + 48);
                char c = char(k+48);
                //check row, column, grid;
                if( checkRow(sudoku, i, c) 
                    && checkCol(sudoku, j, c) 
                    && checkGrid(sudoku, i, j, c)){

                        sudoku[i][j] = char(k);
                        solve(sudoku, i+1, j);
                        sudoku[i][j] = '.';
                    

                }
            }

        }
        else{
            solve(sudoku, i+1, j);
        }
    }




int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif


	vector<vector<char>> sudoku(9, vector<char>(9));

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>sudoku[i][j];
		}
	}

	solve(sudoku, 0, 0);

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<sudoku[i][j]<<" ";
		}
		cout<<endl;
	}


    return 0;
}