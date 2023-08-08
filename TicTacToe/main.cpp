#include <iostream>
#include "Player.h"
using namespace std;

const char* yesOrNo[4] = { "(y)es", "(n)o" };

char validChoice();

int main() {
	bool flag = false;
	while (!flag) {

		Player newPlayer;
		do {
			newPlayer.playerSelect();
			newPlayer.displayBoard();


		} while (!newPlayer.checkWinner());
		newPlayer.winnerMsg();
		cout << "Would you like to play again? Y or N" << endl;
		if (validChoice() == 'n') {
			flag = true;
		}
		else {
			Player newPlayer;
		}

		
	}
	cout << "Thanks for playing!";
	return 0;
}

char validChoice() {
	bool isValid = false;
	char input[4];
	cin >> input;
	do {
		if (tolower(input[0]) == yesOrNo[0][1] || tolower(input[0]) == yesOrNo[1][1]) {//Checks with constant array for either n or y
			isValid = true;
		}
		else {
			cout << "Error. Please enter y or n" << endl;
			cin >> input;
		}

	} while (!isValid);
	return input[0];//Returns either y or n
}//end validChoice