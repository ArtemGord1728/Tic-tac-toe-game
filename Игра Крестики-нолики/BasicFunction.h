#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>

class Tic_tac_toe_Game
{
public:
	void allNull();
	void displayMap();
	bool input();
	short int move();
	void ExitGame();
	void nextMove();
	void selectCrossZero();
	short int whoWin();
	void winner();

private:
	void line();
};