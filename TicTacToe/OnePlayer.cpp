#include "OnePlayer.h";
#include <iostream>
using namespace std;

void OnePlayer::playerSelect() {
	if (playerNum == 1) {
		do {
			cout << "Please select a position" << endl;
			cin >> position;
		} while (!fillBoard(position));
		playerNum++;
		symbol = 'O';
	}
	else if (playerNum == 2) {
		do {
			position = 1 + (rand() % 10);
		} while (!botSelection(position));
		playerNum--;
		symbol = 'X';
		cout << "The bot chose position: " << position << endl;
	}

}

void OnePlayer::winnerMsg() {
	if (winner == 1) {
		cout << "You have won!" << endl;
	}
	else if (winner == 2) {
		cout << "Bot has won!" << endl;
	}
	else {
		cout << " You have tied!" << endl;
	}
}

bool OnePlayer::botSelection(int position) {
	switch (position) {
	case 1:
		if (gameBoard[0][0] == def) {
			gameBoard[0][0] = symbol;
			return true;
		}
		else {
			return false;
		}
	case 2:
		if (gameBoard[0][1] == def) {
			gameBoard[0][1] = symbol;
			return true;
		}
		else {
			return false;
		}
	case 3:
		if (gameBoard[0][2] == def) {
			gameBoard[0][2] = symbol;
			return true;
		}
		else {
			return false;
		}
	case 4:
		if (gameBoard[1][0] == def) {
			gameBoard[1][0] = symbol;
			return true;
		}
		else {
			return false;
		}
	case 5:
		if (gameBoard[1][1] == def) {
			gameBoard[1][1] = symbol;
			return true;
		}
		else {
			return false;
		}
	case 6:
		if (gameBoard[1][2] == def) {
			gameBoard[1][2] = symbol;
			return true;
		}
		else {
			return false;
		}
	case 7:
		if (gameBoard[2][0] == def) {
			gameBoard[2][0] = symbol;
			return true;
		}
		else {
			return false;
		}
	case 8:
		if (gameBoard[2][1] == def) {
			gameBoard[2][1] = symbol;
			return true;
		}
		else {
			return false;
		}
	case 9:
		if (gameBoard[2][2] == def) {
			gameBoard[2][2] = symbol;
			return true;
		}
		else {
			return false;
		}
	default:
		return false;
	}
}