#include <iostream>
#include "Player.h"
#include "OnePlayer.h"
using namespace std;

const char* yesOrNo[4] = { "(y)es", "(n)o" };

char validChoice();

int main() {
	srand((unsigned)time(NULL));//Set a seed value for random number generator
	int choice;
	bool prgEnd = false;
	cout << "Welcome to Tic Tac Toe! How many players? 1 or 2." << endl;
	do {
		cin >> choice;

		if (choice == 2) {
			bool twoPlayer = false;
			while (!twoPlayer) {

				Player newPlayer;
				do {
					newPlayer.playerSelect();
					newPlayer.displayBoard();


				} while (!newPlayer.checkWinner());
				newPlayer.winnerMsg();
				cout << "Would you like to play again? Y or N" << endl;
				if (validChoice() == 'n') {
					twoPlayer = true;
					prgEnd = true;

				}
				else {
					cout << "Would you like to switch modes? Y or N?" << endl;
					if (validChoice() == 'n') {
						Player newPlayer;
					}
					else {
						twoPlayer = true;
						cout << "How Many Players? 1 or 2?" << endl;
					}
				}


			}
		}
		else if (choice == 1) {
			bool onePlayer = false;
			while (!onePlayer) {
				OnePlayer newGame;
				do {
					newGame.playerSelect();
					newGame.displayBoard();
				} while (!newGame.checkWinner());
				newGame.winnerMsg();
				cout << "Would you like to play again? Y or N" << endl;
				if (validChoice() == 'n') {
					onePlayer = true;
					prgEnd = true;
				}
				else {
					cout << "Would you like to switch modes? Y or N?" << endl;
					if (validChoice() == 'n') {
						OnePlayer newGame;
					}
					else {
						onePlayer = true;
						cout << "How Many Players? 1 or 2?" << endl;
					}
				}
			}
		}
		else {
			cout << "Not a valid entry, please try again." << endl;
		}


		
	} while (!prgEnd);


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