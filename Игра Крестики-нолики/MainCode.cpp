#include "BasicFunction.h"


// By default, all cells are empty
void Tic_tac_toe_Game::allNull()
{
	setlocale(LC_ALL, "ru");

	for (int i = 0; i < A; i++)
		for (int j = 0; j < B; j++)
			MAP[i][j] = NULL_FIELD;
}



//***************************Drawing cells **************************/  
/********************************************************************/
void Tic_tac_toe_Game::line()
{
	setlocale(LC_ALL, "ru");

	for (int i = 0; i < A; i++)
		std::cout << "--";
	std::cout << "-" << std::endl;
}


void Tic_tac_toe_Game::displayMap()
{
	setlocale(LC_ALL, "ru");

	std::cout << "Step ¹ " << Nmove << std::endl;
	std::cout << std::endl;

	std::cout << "\t X";
	for (int i = 0; i < A; i++)
		std::cout << " " << i + 1 << "  ";
	std::cout << std::endl;



	std::cout << "\tY";
	line();

	for (int i = 0; i < A; i++)
	{
		std::cout << "\t" << i + 1 << "| ";
		for (int j = 0; j < B; j++)
		{
			std::cout << MAP[i][j] << " | ";
		}
		std::cout << std::endl;
		std::cout << "\t ";
		line();
	}
	std::cout << std::endl << std::endl;
	X = Y = 0;
}
/**********************************************************************/
/**********************************************************************/


// Enter coordinates for X or 0
bool Tic_tac_toe_Game::input()
{
	std::cout << "The player is walking " << whoMove << std::endl;
	std::cout << "Enter the X Y coordinate from 1 to " << A << ": ";
	if ((!(std::cin >> X) || !(std::cin >> Y)) || ((!(X < (A + 1) && X > 0) || !(Y < (B + 1) && Y > 0))) || (!(MAP[--Y][--X] == NULL_FIELD)))
	{
		std::cin.clear();
	}
	else
		return true;
}


// Displays crosses and zeros
short int Tic_tac_toe_Game::move()
{
	Nmove++;

	setlocale(LC_ALL, "ru");

	if (whoMove == symbol_cross)
	{
		MAP[Y][X] = symbol_cross;
		return symbol_cross;
	}

	if (whoMove == symbol_zero)
	{
		MAP[Y][X] = symbol_zero;
		return symbol_zero;
	}
}


// Exits the game
void Tic_tac_toe_Game::ExitGame()
{
	std::cout << "Continue to play (check 1 or 2)?" << std::endl;
	std::cout << std::endl;
	std::cout << "\t" << "1." << exitGame << "\t" << "2." << dontExitGame << std::endl;

	std::cin >> YesOrNo;

	switch (YesOrNo)
	{
	case 1:
		allNull();
		selectCrossZero();

		do
		{
			system("cls");
			displayMap();

			while (!input())
			{
				system("cls");
				displayMap();
			}
			move();
			whoWin();
			nextMove();
		} while ((win == NULL_FIELD) && (Nmove < A * A + 1));

		winner();
		ExitGame();
		break;

	case 2:
		_getch();
		break;
	}
}


// Transmits the step to another player
void Tic_tac_toe_Game::nextMove()
{
	setlocale(LC_ALL, "ru");

	/*******Experimental string for future bot (It will walk Zero)******/
	std::cout << "Walking bot" << std::endl;
	/*******************************************************************/
}


// Allows you to select the sign
void Tic_tac_toe_Game::selectCrossZero()
{
	char cross = 'X';
	char zero = 'O';
	char cross_Or_zero;

	std::cout << "Choose a sign: " << std::endl;
	std::cout << "\t" << cross << "\t" << zero << std::endl;

	std::cin >> cross_Or_zero;

	if (cross_Or_zero == 'X' || cross_Or_zero == 'x')
	{
		whoMove = symbol_cross;
	}
	else
	{
		whoMove = symbol_zero;
	}
	system("cls");
}


short int Tic_tac_toe_Game::whoWin()
{
	setlocale(LC_ALL, "ru");

	short int a = 0;
	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < B - 1; j++)
			if ((MAP[i][j] == MAP[i][j + 1]) && (MAP[i][j] != NULL_FIELD))
				a++;
		if (a == B - 1)
		{
			win = whoMove;
			return i + 1;//columns
		}
		else
			a = 0;
	}

	a = 0;

	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < B - 1; j++)
			if ((MAP[j][i] == MAP[j + 1][i]) && (MAP[j][i] != NULL_FIELD))
				a++;
		if (a == B - 1)
		{
			win = whoMove;
			return i + 4;//lines
		}
		else
			a = 0;
	}


	for (int i = 0, j = A - 1; i < A; i++, j--)
		if ((MAP[i][j] == MAP[i + 1][j - 1]) && (MAP[i][j] != NULL_FIELD))
			a++;
	if (a == B - 1)
	{
		win = whoMove;
		return 7;
	}
	else
		a = 0;

	for (int i = 0, j = 1; i < A; i++, j++)
		if ((MAP[i][i] == MAP[j][j]) && (MAP[i][i] != NULL_FIELD))
			a++;
	if (a == B - 1)
	{
		win = whoMove;
		return 8;
	}
	else
		a = 0;
}


// Defines the conqueror
void Tic_tac_toe_Game::winner()
{
	setlocale(LC_ALL, "ru");

	system("cls");
	displayMap();

	if (win != NULL_FIELD)
		std::cout << "The player wins - " << win << "!\n";

	else
		std::cout << "Standoff!\n";

	std::cout << std::endl;
}




int main()
{
	setlocale(LC_ALL, "ru");

	Tic_tac_toe_Game ttg;

	ttg.allNull();
	ttg.selectCrossZero();
	do
	{
		system("cls");
		ttg.displayMap();

		while (!ttg.input())
		{
			system("cls");
			ttg.displayMap();
		}
		ttg.move();
		ttg.whoWin();
		ttg.nextMove();
	} while ((ttg.win == NULL_FIELD) && (ttg.Nmove < ttg.A * ttg.A + 1));

	ttg.winner();

	ttg.ExitGame();
	return 0;
}