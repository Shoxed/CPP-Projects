#pragma once
class Player {
protected:
	char symbol; //Represents either X or O
	int position; //Position on board to place X or O
	int playerNum; //Determine whether it's player 1 or 2's turn
	char gameBoard[3][3];
	int winner;
public:
	char def = '*';

public:
	//Constructor 
	Player();
	Player(char symbol, int position, int playerNum);
	//Getters 
	char getSymbol();
	int getPosition();
	int getPlayerNum();

	void playerSelect();//Alternates player's turns and requests for a selection space on board 
	bool fillBoard(int position);//Checks and makes sure board space is not 
	bool checkWinner();//Checks for winner or tie
	void displayBoard();//Displays board 
	void winnerMsg();//Displays a winning message/tie
};

