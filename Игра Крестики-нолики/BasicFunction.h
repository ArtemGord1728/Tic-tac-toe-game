#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>

#define MapSize 3 // field size
#define NULL_FIELD 0  // empty cell symbol
#define symbol_cross 88  // symbol of the cross
#define symbol_zero 79  // noch symbol

class Tic_tac_toe_Game
{
public:
	short int X, Y, Nmove = 1;
	static const short int A = MapSize, B = MapSize;
	char MAP[A][B];
	char whoMove = NULL_FIELD, win = NULL_FIELD;
	std::string exitGame = "Yes";
	std::string dontExitGame = "No";
	int YesOrNo;


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