#include "Learner.h"
#include <vector>
#include <cstdlib>
#include <iostream> 
#include <cmath>

using namespace std;

LearnAi::LearnAi(int initialPlayer) {
	states.resize(19682);  //Maximum number of states
	record = 0;   //Records win/tie/loss record e.g. (10, 8, 0) is 10 wins, 8 ties, 0 losses
	player = initialPlayer;
	counter = 0;
}

int LearnAi::baseThreeInterpreter() {
	int baseTen = 0;
	int index = 0;
	for (int i = 0; i < baseThree.size(); ++i) {
		baseTen = baseTen + baseThree[i] * pow(3, baseThree.size() - 1 - i);
	}
	return baseTen;
}

void LearnAi::convertBoardState(Board& board) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (!(baseThree.size() == 0 && board.intAt(i, j) == 0) ) {
				baseThree.push_back(board.intAt(i, j));
			}
		}
	}
}

void LearnAi::developPossibleMoves(Board& board, int currState) {
//	board.PrintBoard();
//	cout << currState << endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (board.intAt(i, j) == 0) {
				possibleMove temp(i, j, 100);
				states[currState].push_back(temp);
			}
		}
	}
}

int LearnAi::getRandMove(int currState) {
	int sum = 0;
	for (int i = 0; i < states[currState].size(); i ++) {
		sum += states[currState][i].score;
	}
	int output = rand() % sum; //Gets random number between 0 and Sum
	int index = 0;	
	while (states[currState][index].score < output) {
		output -= states[currState][index].score;
		index ++;
	}
	return index;
}
		

void LearnAi::getAiMove(int player, Board& board) {
	clearBaseThree();
	convertBoardState(board);
	int currState = baseThreeInterpreter();
	if (states[currState].empty()) {
		developPossibleMoves(board, currState);
	}
	int indexMove = getRandMove(currState);
	Move newMove(indexMove, currState);
	board.SetVal(player, states[currState][indexMove]._x, states[currState][indexMove]._y);
	currPath.push_back(newMove);
}

void LearnAi::updateIfWin() {
	for (int i = 0; i < currPath.size(); i ++) {
		states[currPath[i].state][currPath[i].index].score += 10;
	}
	record ++;
}

void LearnAi::updateIfLoss() {
	for (int i = 0; i < currPath.size(); i ++) {
		if (states[currPath[i].state][currPath[i].index].score != 0) {
			states[currPath[i].state][currPath[i].index].score -= 1;
		}
	}
}
int LearnAi::getWins() {
	return record;
}

int LearnAi::getPlayer() {
	return player;
}

void LearnAi::switchPlayer() {
	if (player == 1) {
		player = 2;
	}
	else {
		player = 1;
	}
	clear();
}

void LearnAi::clear() {
	currPath.clear();
}

void LearnAi::clearBaseThree() {
	baseThree.clear();
}
