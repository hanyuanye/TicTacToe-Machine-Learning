#include "play.h"
#include <iostream>

using namespace std;

void play::switchCurrPlayer(int& currPlayer) {
	if (currPlayer == 1) {
		currPlayer = 2;
	}
	else {
		currPlayer = 1;
	}
}
int play::playAiGame(LearnAi& AiOne, LearnAi& AiTwo) {
	Board board;
	int currPlayer = 1;
	while (board.CheckVictory() == 3) {
		if (AiOne.getPlayer() == currPlayer) {
			AiOne.getAiMove(currPlayer, board);
		}
		else {
			AiTwo.getAiMove(currPlayer, board);
		}
		switchCurrPlayer(currPlayer);
	}
	return board.CheckVictory();
}

void play::playHumanGame(int humanPlayer, LearnAi Ai) {
	Board board;
	int currPlayer = 1;
	while (board.CheckVictory() == 3) {
		if (currPlayer == humanPlayer) {
			recieveHumanMove(currPlayer, board);
		}
		else {
			Ai.getAiMove(currPlayer, board);
		}
		switchCurrPlayer(currPlayer);
	}
	displayWinner(humanPlayer, board.CheckVictory(), board);
}

void play::recieveHumanMove(int currPlayer, Board& board) {
	int row, column;
	board.PrintBoard();
	cout << "Enter the row number: " << endl;
	cin >> row;
	cout << "Enter the column number: " << endl;
	cin >> column;
	board.SetVal(currPlayer, row-1, column-1);
}
			
void play::displayWinner(int humanPlayer, int victor, Board board) {
	board.PrintBoard();
	if (victor == humanPlayer) {
		cout << "The player has won." << endl;
	}
	else if (victor == 0) {
		cout << "The game is a tie. " << endl;
	}
	else {
		cout << "The AI has won. " << endl;
	}
}