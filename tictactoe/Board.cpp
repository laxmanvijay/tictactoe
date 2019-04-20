#include "pch.h"
#include "Board.h"
#include<iostream>
#include<algorithm>

Board::Board() {
		std::cout << "board created" << std::endl;
}

void Board::printBoard() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << board[i][j] << "  ";
			}
			std::cout << std::endl;
		}
}

bool Board::setMove(int i, int j, char move) {
		if (i >= 3 || i < 0 || j >= 3 || j < 0) {
			return false;
		}
		else if (board[i][j] != '.') {
			return false;
		}
		board[i][j] = move;
		return true;
	}

bool Board::isBoardFull() {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (board[i][j] == '.')
					return false;
		return true;
	}

int Board::evaluate()
	{
		char player = 'X';
		char opponent = 'O';

		// Checking for Rows for X or O victory. 
		for (int row = 0; row < 3; row++)
		{
			if (board[row][0] == board[row][1] &&
				board[row][1] == board[row][2])
			{
				if (board[row][0] == player)
					return +10;
				else if (board[row][0] == opponent)
					return -10;
			}
		}

		// Checking for Columns for X or O victory. 
		for (int col = 0; col < 3; col++)
		{
			if (board[0][col] == board[1][col] &&
				board[1][col] == board[2][col])
			{
				if (board[0][col] == player)
					return +10;

				else if (board[0][col] == opponent)
					return -10;
			}
		}

		// Checking for Diagonals for X or O victory. 
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
		{
			if (board[0][0] == player)
				return +10;
			else if (board[0][0] == opponent)
				return -10;
		}

		if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
		{
			if (board[0][2] == player)
				return +10;
			else if (board[0][2] == opponent)
				return -10;
		}

		// Else if none of them have won then return 0 
		return 0;
}

int Board::minimax(int depth, bool isMax)
{
	int score = evaluate();
	if (score == 10)
		return score;

	if (score == -10)
		return score;

	if (isBoardFull() == false)
		return 0; 
	if (isMax)
	{
		int best = -1000;
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if (board[i][j] == '.'){
					board[i][j] = opponent;
					best = std::max(best,minimax(depth + 1, !isMax));
					board[i][j] = '.';
				}
			}
		}
		return best;
	}
	else
	{
		int best = 1000;
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if (board[i][j] == '.'){
					board[i][j] = player;
					best = std::min(best,minimax(depth + 1, !isMax));
					board[i][j] = '.';
				}
			}
		}
		return best;
	}
}

bool Board::generateMove() {

	int bestVal = -1000;
	pair bestMove;
	bestMove.row = -1;
	bestMove.col = -1;
	std::cout << "generating next move" << std::endl;
 
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (board[i][j] == '.'){ 
				board[i][j] = player;
				int moveVal = minimax(0, true);
				board[i][j] = '.';
				if (moveVal > bestVal){
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}
	setMove(bestMove.row,bestMove.col,'O');
	return true;
}