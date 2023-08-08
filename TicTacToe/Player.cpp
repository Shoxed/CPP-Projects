#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
	symbol = 'X';
	position = 0;
	playerNum = 1;
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			gameBoard[i][j] = def;
		}
	}
	
}
Player::Player(char symbol, int position, int playerNum) {
	this->symbol = symbol;
	this->position = position;
	this->playerNum = playerNum;
}

char Player::getSymbol() {
	return symbol;
}

int Player::getPosition() {
	return position;
}

int Player::getPlayerNum() {
	return playerNum;
}

void Player::playerSelect() {
	cout << "Player: " << playerNum << " Please choose a position you would like to place an '" << symbol << "'" << endl;
	do {
		cin >> position;
	} while (!fillBoard(position));
	if (playerNum == 1) {
playerNum++;
symbol = 'O';
	}
 else if (playerNum == 2) {
	 playerNum--;
	 symbol = 'X';
	}
}

bool Player::fillBoard(int position) {
	switch (position) {
	case 1:
		if (gameBoard[0][0] == def) {
			gameBoard[0][0] = symbol;
			return true;
		}
		else {
			cout << "Slot is already filled. Try again.";
			return false;
		}
	case 2:
		if (gameBoard[0][1] == def) {
			gameBoard[0][1] = symbol;
			return true;
		}
		else {
			cout << "Slot is already filled. Try again.";
			return false;
		}
	case 3:
		if (gameBoard[0][2] == def) {
			gameBoard[0][2] = symbol;
			return true;
		}
		else {
			cout << "Slot is already filled. Try again.";
			return false;
		}
	case 4:
		if (gameBoard[1][0] == def) {
			gameBoard[1][0] = symbol;
			return true;
		}
		else {
			cout << "Slot is already filled. Try again.";
			return false;
		}
	case 5:
		if (gameBoard[1][1] == def) {
			gameBoard[1][1] = symbol;
			return true;
		}
		else {
			cout << "Slot is already filled. Try again.";
			return false;
		}
	case 6:
		if (gameBoard[1][2] == def) {
			gameBoard[1][2] = symbol;
			return true;
		}
		else {
			cout << "Slot is already filled. Try again.";
			return false;
		}
	case 7:
		if (gameBoard[2][0] == def) {
			gameBoard[2][0] = symbol;
			return true;
		}
		else {
			cout << "Slot is already filled. Try again.";
			return false;
		}
	case 8:
		if (gameBoard[2][1] == def) {
			gameBoard[2][1] = symbol;
			return true;
		}
		else {
			cout << "Slot is already filled. Try again.";
			return false;
		}
	case 9:
		if (gameBoard[2][2] == def) {
			gameBoard[2][2] = symbol;
			return true;
		}
		else {
			cout << "Slot is already filled. Try again.";
			return false;
		}
	default:
		cout << "Invalid Selection, please try again.";
		return false;
	}
}

void Player::displayBoard() {
	for (int i = 0; i <= 2; i++) {
			for (int j = 0; j <= 2; j++){
				if (j != 2) {
					cout << gameBoard[i][j] << "|";
				}
				else {
					cout << gameBoard[i][j];
				}
			}
		cout << endl;
	}

}
//Checks all possible 
bool Player::checkWinner() {
	//Checks for Vertical/Horizontal Three-In-A-Row 
	for (int i = 0; i <= 2; i++) {
		if (gameBoard[i][0], gameBoard[i][1], gameBoard[i][2] == 'X' || gameBoard[0][i], gameBoard[1][i], gameBoard[2][i] == 'X') {
			winner = 1;
			return true;
		}
		else if (gameBoard[i][0], gameBoard[i][1], gameBoard[i][2] == 'O' || gameBoard[0][i], gameBoard[1][i], gameBoard[2][i] == 'O') {
			winner = 2;
			return true;
		}
	}
	//Checks for Diagonal Three-In-A-Row
	if (gameBoard[0][0], gameBoard[1][1], gameBoard[2][2] == 'X' || gameBoard[0][2], gameBoard[1][1], gameBoard[2][0] == 'X') {
		winner = 1;
		return true;
	}
	else if (gameBoard[0][0], gameBoard[1][1], gameBoard[2][2] == 'O' || gameBoard[0][2], gameBoard[1][1], gameBoard[2][0] == '0') {
		winner = 2;
		return true;
	}
	//Checks all Board Spaces for Tie
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if (gameBoard[i][j] == '*') {
				return false; //Iterates through entire board and if * is found, that means game is not over 
			} 
		}
	}

	winner = 0; //After checking the entire board, returns 0 meaning a tie has happened 
	return true;
}

void Player::winnerMsg() {
	if (winner == 1) {
		cout << "Player 1 has won!" << endl;
	}
	else if (winner == 2) {
		cout << "Player 2 has won!" << endl;
	}
	else {
		cout << "Player have tied!" << endl;
	}
}
