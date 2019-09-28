#include "BasicFunctions.h"


// By default, all cells are empty
void Tic_tac_toe_Game::Null_All_Cell()
{
	setlocale(LC_ALL, "ru");

	for (int i = 0; i < A; i++)
		for (int j = 0; j < B; j++)
			MAP[i][j] = NULL_FIELD;
}



//***************************Drawing cells **************************/  
/********************************************************************/
void Tic_tac_toe_Game::Line()
{
	setlocale(LC_ALL, "ru");

	for (int i = 0; i < A; i++)
		std::cout << "--";
	cout << "-" << endl;
}

short int Tic_tac_toe_Game::getMove()
{
	return Nmove;
}

void Tic_tac_toe_Game::ShowMap()
{
	setlocale(LC_ALL, "ru");

	cout << "Step ¹ " << getMove() << endl;
	cout << endl;

	cout << "\t X";
	for (int i = 0; i < A; i++)
		cout << " " << i + 1 << "  ";
	cout << endl;



	cout << "\tY";
	Line();

	for (int i = 0; i < A; i++)
	{
		cout << "\t" << i + 1 << "| ";
		for (int j = 0; j < B; j++)
		{
			cout << MAP[i][j] << " | ";
		}
		cout << endl;
		cout << "\t ";
		Line();
	}
	cout << endl << endl;
	X = Y = 0;
}
/**********************************************************************/
/**********************************************************************/


// Enter coordinates for X or 0
bool Tic_tac_toe_Game::Input()
{
	cout << "The player is walking " << whoMove << endl;
	cout << "Enter the X Y coordinate from 1 to " << A << ": ";
	if ((!(cin >> X) || !(cin >> Y)) || ((!(X < (A + 1) && X > 0) || !(Y < (B + 1) && Y > 0))) || (!(MAP[--Y][--X] == NULL_FIELD)))
	{
		cin.clear();
	}
	else
		return true;
}


// Displays crosses and zeros
short int Tic_tac_toe_Game::Move()
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
	cout << "Continue to play (check 1 or 2)?" << endl;
	cout << endl;
	cout << "\t" << "1." << exitGame << "\t" << "2." << dontExitGame << endl;

	cin >> Choice;

	switch (Choice)
	{
	case 1:
		Null_All_Cell();
		selectCrossZero();

		do
		{
			system("cls");
			ShowMap();

			while (!Input())
			{
				system("cls");
				ShowMap();
			}
			Move();
			AlgorithmSearchWin();
			NextMove();
		} while ((win == NULL_FIELD) && (Nmove < A * A + 1));

		Winner();
		ExitGame();
		break;

	case 2:
		_getch();
		break;
	}
}


// Transmits the step to another player
void Tic_tac_toe_Game::NextMove()
{
	setlocale(LC_ALL, "ru");

	whoMove == symbol_cross ? whoMove = symbol_zero : whoMove = symbol_cross;
}


// Allows you to select the sign
void Tic_tac_toe_Game::selectCrossZero()
{
	char cross = 'X';
	char zero = 'O';
	char cross_Or_zero;

link:
	cout << "Choose a sign: " << endl;
	cout << "\t" << cross << "\t" << zero << endl;

	cin >> cross_Or_zero;

	switch (cross_Or_zero)
	{
	case 'x':
		whoMove = symbol_cross;
		break;


	case 'o':
		whoMove = symbol_zero;
		break;


	default:
		cout << "There is no such sign. Choose a sign. Press \"Enter\"" << endl;
		system("cls");
		goto link;
		break;
	}


	system("cls");
}


short int Tic_tac_toe_Game::AlgorithmSearchWin()
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
			return i + 1;
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
			return i + 4;
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
void Tic_tac_toe_Game::Winner()
{
	system("cls");
	ShowMap();

	win != NULL_FIELD ? cout << "The player wins - " << win << "!\n" : cout << "Standoff!\n";

	cout << endl;
}



int main()
{
	setlocale(LC_ALL, "ru");

	Tic_tac_toe_Game ttg;

	ttg.Null_All_Cell();
	ttg.selectCrossZero();
	do
	{
		system("cls");
		ttg.ShowMap();

		while (!ttg.Input())
		{
			system("cls");
			ttg.ShowMap();
		}
		ttg.Move();
		ttg.AlgorithmSearchWin();
		ttg.NextMove();
	} while ((ttg.win == NULL_FIELD) && (ttg.getMove() < pow(ttg.A, 2) + 1));

	ttg.Winner();
	ttg.ExitGame();
	return 0;
}