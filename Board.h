#pragma once
class Board 
{
public:
	char valAt(int x, int y);
	int intAt(int x, int y);
	int getSize();
	void SetVal(int player, int x, int y);
	void PrintBoard();
	int CheckVictory();
	void clear();
	void displayWinner(int victor, int humanPlayer, int AiPlayer);
	//Constructor
	Board();
private:
	int board[3][3];
	int size;
};
