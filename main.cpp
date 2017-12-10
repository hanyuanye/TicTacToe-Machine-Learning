#include <iostream>
#include "game.h"
#include <time.h>

using namespace std;

int main()
{
	int winner, first;
	LearnAi AiOne(1);
	LearnAi AiTwo(2);
	cout << "Grinding the computer's gears... " << endl;
	for (int i = 0; i < 10000000; i ++) {
		winner = play::playAiGame(AiOne, AiTwo);
		if (winner == AiOne.getPlayer()) {
			AiOne.updateIfWin();
			AiTwo.updateIfLoss();
		}
		else if (winner == AiTwo.getPlayer()) {
			AiTwo.updateIfWin();
			AiOne.updateIfLoss();
		}
		AiOne.switchPlayer();
		AiTwo.switchPlayer();
	}
	int playAgain = 0;
	do {
		cout << "Press 1 to go first, 2 to go second. "<< endl;
		cin >> first;
		if (AiOne.getWins() > AiTwo.getWins()) {
			play::playHumanGame(first, AiOne);
		}
		else {
			play::playHumanGame(first, AiTwo);
		}
		cout << "Press 1 to play again, 2 to end. " << endl;
		cin >> playAgain;
	}
	while (playAgain == 1);
}
	
	