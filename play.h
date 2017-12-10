#include "Learner.h"

namespace play
{
	void switchCurrPlayer(int& currPlayer);
	int playAiGame(LearnAi& AiOne, LearnAi& AiTwo);
	void recieveHumanMove(int currPlayer, Board& board);
	void playHumanGame(int humanPlayer, LearnAi Ai);
	void displayWinner(int humanPlayer, int victor, Board board);
};
		