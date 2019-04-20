#include "pch.h"
#include <iostream>
#include <vector>
#include"Board.h"

void multiPlayer() {
	std::cout << "multi player mode"<<std::endl;
	std::cout << "initial board state"<<std::endl;
	int i, j;
	Board b;
	int player1 = 1;
	while (1) {
		b.printBoard();
		int eval = b.evaluate();
		if (!b.isBoardFull() && (eval ==0)) {
			std::cout << "enter the position" << std::endl;
			std::cin >> i;
			std::cin >> j;
			if (player1) {
				bool o=b.setMove(i, j, 'X');
				if (o == false) {
					std::cout << "the position is already placed or input is out of bounds" << std::endl;
					continue;
				}
				player1 = 0;
			}
			else {
				bool o = b.setMove(i, j, 'O');
				if (o == false) {
					std::cout << "the position is already placed or input is out of bounds" << std::endl;
					continue;
				}
				player1 = 1;
			}
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