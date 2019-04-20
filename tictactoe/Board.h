#pragma once
#ifndef BOARD_H
#define BOARD_H
class Board
{
private:
	char board[3][3] = { {'.','.','.'},
					{'.','.','.'},
					{'.','.','.'} };
	struct pair {
		int row;
		int col;
	};
	char player = 'O', opponent = 'X';
public:
	Board();
	void printBoard();
	bool setMove(int i, int j, char move);
	bool isBoardFull();
	int evaluate();
	bool generateMove();
	int minimax(int depth, bool isMax);
};
#endif

