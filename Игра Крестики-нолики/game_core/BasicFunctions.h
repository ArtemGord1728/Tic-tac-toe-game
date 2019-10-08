#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include<math.h>
#include <ctime>

using namespace std;

#define MapSize 3 // field size
#define NULL_FIELD 0  // empty cell symbol
#define symbol_cross 88  // symbol of the cross
#define symbol_zero 79  // noch symbol

class Tic_tac_toe_Game
{
public:
	static const short int A = MapSize, B = MapSize;
	char MAP[A][B];
	char whoMove = NULL_FIELD, win = NULL_FIELD;
	std::string exitGame = "Yes";
	std::string dontExitGame = "No";
	int Choice;


	void null_cells();
	void show_map();
	short int getMove();
	bool input_coordinates();
	uint8_t display();
	void exit_game();
	void next_move();
	void selectCrossZero();
	void select_mode();
	short int algorithm_search_winner();
	void Winner();

private:
	short int X, Y, Nmove = 1;
	void drawing_cells();
};