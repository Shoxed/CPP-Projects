#pragma once
#include "Player.h"
#include <iostream>
using namespace std;

class OnePlayer : public Player {
public:
	void playerSelect();
	void winnerMsg();
	bool botSelection(int position);
};