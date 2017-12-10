#include "Board.h" 
#include <iostream>

using namespace std;
int Tie_val = 0;
int No_val = 0;
int X_val = 1;
int O_val = 2;
int Incomplete_val = 3;

Board::Board() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			board[i][j] = No_val;
		}
	}
}

void Board::displayWinner(int victor, int humanPlayer, int AiPlayer) {
	PrintBoard();
	if (victor == AiPlayer) {
		cout << "The AI has won." << endl;
	}
	else if (victor == humanPlayer) {
		cout << "The player has won." << endl;
	}
	else {
		cout << "The game is a tie. " << endl;
	}
}

char Board::valAt(int x, int y) {
	switch(board[x][y]) {
		case 1:
			return 'X';
			break;
		case 2:
			return 'O';
			break;
		case 0:
			return ' ';
			break;
	}
}

int Board::intAt(int x, int y) {
	return board[x][y];
}

void Board::PrintBoard() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << valAt(i, j) << " | ";
		}
		cout << endl;
	}
	cout << endl << endl << endl;
}

void Board::SetVal(int player, int x, int y) {
	if (player == 1) {
		board[x][y] = X_val;
	}
	else if (player == 2) {
		board[x][y] = O_val;
	}
	else {
		board[x][y] = No_val;
	}
}

void Board::clear() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			board[i][j] = No_val;
		}
	}
}
int Board::CheckVictory() {
	for (int i = 0; i < 3; ++i) {  //Check Row 
		if (board[i][0] == board[i][1] && board[i][2] == board [i][1]) {
			if (board[i][0] == X_val) {
				return X_val;
			}
			else if (board[i][0] == O_val) {
				return O_val;
			}
		}
	}
	for (int i = 0; i < 3; ++i) { //Check Column 
		if (board[0][i] == board[1][i] && board[2][i] == board [1][i]) {
			if (board[0][i] == X_val) {
				return X_val;
			}
			else if (board[0][i] == O_val) {
				return O_val;
			}
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) { //Check Diagonal 
		if (board[1][1] == X_val) {
			return X_val;
		}
		else if (board[1][1] == O_val) {
			return O_val;
		}
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != No_val) {
		if (board[1][1] == X_val) {
			return X_val;
		}
		else if (board[1][1] == O_val) {
			return O_val;
		}
	}
	for (int i = 0; i < 3; ++i) { //Check Tie 
		for (int j = 0; j < 3; ++j) {
			if (board[i][j] == No_val) {
				return Incomplete_val;  //Not tie
			}
		}
	}
	return Tie_val;  //Tie
}
	
		

