#include "Board.h"
#include <vector>

// Set weights of all moves to 1
// Loop 1000000 times
// Play a game
/*
  |   | O
  | X | X
  |   |  
  this resolves to "001020002" which can be interpreted in base 3 
  and converted back as a unique base 10 number
*/
// For each step, record the move used
// Record result of game, if win
// Record path to victory using ternary representation, e.g. 1 - > 10 - > 12 - > 20 etc.
// For each score which represents a unique board state, keep a vector of possible moves
// Then increase the probability that the chosen winning move is picked
// Struct system is, 
struct Move {
	int index;
	int state;
	Move(int indexMove, int currState): index(indexMove), state(currState){}
};

struct possibleMove {
	int _x;
	int _y;
	int score;
	possibleMove(int x, int y, int score): _x(x), _y(y), score(score){}
};

class LearnAi {
	public:
		int baseThreeInterpreter(); //Takes in representation as "001020002" etc. and parses it as ternary, converts to base 10
		void clear();
		void convertBoardState(Board& board);
		void getAiMove(int player, Board& board); //Randomly generates a move based on current boardstate possibleMove weightings
		void updateIfWin();
		void updateIfLoss();
		void developPossibleMoves(Board& board, int currState); //Generates possible moves if new state
		int getRandMove(int currState); //Generates random move based on weightings
		int getWins(); //Returns number of wins this AI has won
		int getPlayer(); //Returns if player is 1(X) or 2(O)
		void switchPlayer(); //Switches the player from X to O
		
	LearnAi(int initialPlayer); //Constructor
	
	private:
		void clearBaseThree();
		std::vector<Move> currPath;
		std::vector<int> baseThree;
		std::vector< std::vector <possibleMove> > states;
		int record;
		int player;
		int counter;
};	
	

