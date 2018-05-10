#include <iostream>
#include <conio.h>
#include <ctime>


using namespace std;

#define mapSize 3 // field size

#define NULL_Field 0  // empty cell symbol
#define symbol_cross 88  // symbol of the cross
#define symbol_zero 79  // noch symbol


const short int A = mapSize, B = mapSize;
short int X, Y, Nmove = 1;
char whoMove = NULL_Field, win = NULL_Field;
char MAP[A][B];

void allNull()
{

	for (int i = 0; i < A; i++)
		for (int j = 0; j < B; j++)
			MAP[i][j] = NULL_Field;
}


// A function that randomly selects a player (X or 0)
void randomFirstMove()
{

	srand(time(0));
	if (rand() & 1)
		whoMove = symbol_cross;
	else
		whoMove = symbol_zero;
}

void line()
{

	for (int i = 0; i < A; i++)
		cout << "--";
	cout << "-" << endl;
}

void displayMap()
{
	cout << "Õîä ¹ " << Nmove << endl;
	cout << endl;

	cout << "\t X";
	for (int i = 0; i < A; i++)
		cout << " " << i + 1 << "  ";
	cout << endl;

	cout << "\tY";
	line();


	for (int i = 0; i < A; i++)
	{
		cout << "\t" << i + 1 << "| ";
		for (int j = 0; j < B; j++)
		{
			cout << MAP[i][j] << " | ";
		}
		cout << endl;
		cout << "\t ";
		line();
	}
	cout << endl << endl;
	X = Y = 0;
}

bool input()
{
	cout << "The player is walking " << whoMove << endl;
	cout << "Enter the X Y coordinate from 1 to " << A << ": ";
	if ((!(cin >> X) || !(cin >> Y)) || ((!(X < (A + 1) && X > 0) || !(Y < (B + 1) && Y > 0))) || (!(MAP[--Y][--X] == NULL_Field)))
	{
		cin.clear(); while (cin.get() != '\n');
		return false;
	}
	else
		return true;
}

short int move()
{
	Nmove++;

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

void nextMove()
{
	whoMove == symbol_cross ? whoMove = symbol_zero : whoMove = symbol_cross;
}

short int whoWin()
{
	//algorithms for calculating the winning combination on any field

	short int a = 0;
	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < B - 1; j++)
			if ((MAP[i][j] == MAP[i][j + 1]) && (MAP[i][j] != NULL_Field))
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
			if ((MAP[j][i] == MAP[j + 1][i]) && (MAP[j][i] != NULL_Field))
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
		if ((MAP[i][j] == MAP[i + 1][j - 1]) && (MAP[i][j] != NULL_Field))
			a++;
	if (a == B - 1)
	{
		win = whoMove;
		return 7;
	}
	else
		a = 0;

	for (int i = 0, j = 1; i < A; i++, j++)
		if ((MAP[i][i] == MAP[j][j]) && (MAP[i][i] != NULL_Field))
			a++;
	if (a == B - 1)
	{
		win = whoMove;
		return 8;
	}
	else
		a = 0;



}

void winner()
{
	system("cls");
	displayMap();

	if (win != NULL_Field)
		cout << "The player wins - " << win << "!\n";

	else
		cout << "Draw!\n";
}

int main()
{
	allNull();
	randomFirstMove();

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
	} while ((win == NULL_Field) && (Nmove < A*A + 1));


	winner();


	_getch();
	return 0;
}