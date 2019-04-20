#include "pch.h"
#include <iostream>
#include "MultiPlayer.h"
#include "SinglePlayer.h"

int main()
{
	std::cout << "welcome to tic tac toe!"<<std::endl;
	std::cout << "do you wish to play a single player or a multiplayer game" << std::endl;
	int option;
	std::cin >> option;
	switch (option) {
	case 1:
		singlePlayer();
		break;
	case 2:
		multiPlayer();
		break;
	default:
		std::cout << "please choose a valid option" << std::endl;
	}
	std::cout << "press any key to exit" << std::endl;
	int exit;
	std::cin>>exit;
}
