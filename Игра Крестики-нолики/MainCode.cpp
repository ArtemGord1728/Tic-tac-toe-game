#include <iostream>
#include <conio.h>
#include <ctime>


using namespace std;

#define mapSize 3 // field size

#define NULL_Field 0  // empty cell symbol
#define symbol_cross 88  // symbol of the cross
#define symbol_zero 79  // noch symbol


class Tic_tac_toe_Game
{
public:
	short int X, Y, Nmove = 1;
	static const short int A = mapSize, B = mapSize;
	char MAP[A][B];
	char whoMove = NULL_Field, win = NULL_Field;

public:
	void allNull()
	{
		setlocale(LC_ALL, "ru");

		for (int i = 0; i < A; i++)
			for (int j = 0; j < B; j++)
				MAP[i][j] = NULL_Field;
	}


	// A function that randomly selects a player (X or 0)
	void randomFirstMove()
	{
		setlocale(LC_ALL, "ru");

		srand(time(0));
		if (rand() & 1)
			whoMove = symbol_cross;
		else
			whoMove = symbol_zero;
	}

private:
	void line()
	{
		setlocale(LC_ALL, "ru");

		for (int i = 0; i < A; i++)
			cout << "--";
		cout << "-" << endl;
	}

public:
	void displayMap()
	{
		setlocale(LC_ALL, "ru");

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
		setlocale(LC_ALL, "ru");

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
		setlocale(LC_ALL, "ru");

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
		setlocale(LC_ALL, "ru");
		whoMove == symbol_cross ? whoMove = symbol_zero : whoMove = symbol_cross;
	}

	short int whoWin()
	{
		//algorithms for calculating the winning combination on any field

		setlocale(LC_ALL, "ru");

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
		setlocale(LC_ALL, "ru");

		system("cls");
		displayMap();

		if (win != NULL_Field)
			cout << "The player wins - " << win << "!\n";

		else
			cout << "Draw!\n";
	}
};
	int main()
	{
		setlocale(LC_ALL, "ru");

		Tic_tac_toe_Game ttg;

	   ttg.allNull();
	   ttg.randomFirstMove();

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
		} while ((ttg.win == NULL_Field) && (ttg.Nmove < ttg.A *ttg.A + 1));


		ttg.winner();


		_getch();
		return 0;
	}