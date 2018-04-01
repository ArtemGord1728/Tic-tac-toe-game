//игра крестики нолики, можно выбрать любой размер поля, есть ничья
#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

#define mapSize 3 //размер поля

#define NUL 0  // символ пустой клетки
#define P1 88  // символ крестика
#define P2 79  // символ нолика


const short int A = mapSize, B = mapSize;
short int X, Y, Nmove = 1;
char whoMove = NUL, win = NUL;
char MAP[A][B];

void allNull()
{
	for (int i = 0; i < A; i++)
		for (int j = 0; j < B; j++)
			MAP[i][j] = NUL;
}

void randomFirstMove()
{
	srand(time(0));
	if (rand() & 1)
		whoMove = P1;
	else
		whoMove = P2;
}

void line()
{
	for (int i = 0; i < A; i++)
		cout << "--";
	cout << "-" << endl;
}

void displayMap()
{
	cout << "Ход № " << Nmove << endl;
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
	cout << "Ход игрока " << whoMove << endl;
	cout << "Введите координату X Y от 1 до " << A << ": ";
	if ((!(cin >> X) || !(cin >> Y)) || ((!(X < (A + 1) && X > 0) || !(Y < (B + 1) && Y > 0))) || (!(MAP[--Y][--X] == NUL)))
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

	if (whoMove == P1)
	{
		MAP[Y][X] = P1;
		return P1;
	}

	if (whoMove == P2)
	{
		MAP[Y][X] = P2;
		return P2;
	}
}

void nextMove()
{
	whoMove == P1 ? whoMove = P2 : whoMove = P1;
}

short int whoWin()
{
	//алгоритмы для вычисления победной комбинации на любом поле

	short int a = 0;
	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < B - 1; j++)
			if ((MAP[i][j] == MAP[i][j + 1]) && (MAP[i][j] != NUL))
				a++;
		if (a == B - 1)
		{
			win = whoMove;
			return i + 1;//столбцы
		}
		else
			a = 0;
	}

	a = 0;

	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < B - 1; j++)
			if ((MAP[j][i] == MAP[j + 1][i]) && (MAP[j][i] != NUL))
				a++;
		if (a == B - 1)
		{
			win = whoMove;
			return i + 4;//строки
		}
		else
			a = 0;
	}


	for (int i = 0, j = A - 1; i < A; i++, j--)
		if ((MAP[i][j] == MAP[i + 1][j - 1]) && (MAP[i][j] != NUL))
			a++;
	if (a == B - 1)
	{
		win = whoMove;
		return 7;
	}
	else
		a = 0;

	for (int i = 0, j = 1; i < A; i++, j++)
		if ((MAP[i][i] == MAP[j][j]) && (MAP[i][i] != NUL))
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

	if (win != NUL)
		cout << "Выиграл игрок " << win << "!\n";

	else
		cout << "Ничья!\n";
}

int main()
{
	setlocale(0, "Russian");

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
	} while ((win == NUL) && (Nmove < A*A + 1));


	winner();


	_getch();
	return 0;
}