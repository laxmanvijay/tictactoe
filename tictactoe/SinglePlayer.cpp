#include "pch.h"
#include <iostream>
#include "Board.h"

void singlePlayer() {
	std::cout << "single player mode" << std::endl;
	std::cout << "initial board state" << std::endl;
	int i, j;
	Board b;
	while (1) {
		b.printBoard();
		int eval = b.evaluate();
		if (!b.isBoardFull() && (eval == 0)) {
			std::cout << "enter the position" << std::endl;
			std::cin >> i;
			std::cin >> j;
			bool o = b.setMove(i, j, 'X');
			if (o == false) {
				std::cout << "the position is already placed or input is out of bounds" << std::endl;
				continue;
			}
			b.generateMove();
		}
		else {
			int eval = b.evaluate();
			if (b.isBoardFull() && (eval == 0)) {
				std::cout << "its a tie" << std::endl;
			}
			else if (eval == 10) {
				std::cout << "Player 1 wins!" << std::endl;
			}
			else {
				std::cout << "player 2 wins!" << std::endl;
			}
			break;
		}
	}
	std::cout << "game over" << std::endl;
}