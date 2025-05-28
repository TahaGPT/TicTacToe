#include <iostream>
using namespace std;

// function prototypes
void board(char **b, int, int);
bool wcheck(char **b, int, int);
bool d1check(char **b, int, int, char);
bool d2check(char **b, int, int, char);

int main()
{
	const int r = 3;		  // rows
	const int c = 3;		  // columns
	char **b = new char *[r]; // board

	for (int i = 0; i < r; i++)
	{
		*(b + i) = new char[c];
	}

	char n = '1'; // initial number

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{

			*(*(b + i) + j) = n++; // assigning intial increments
		}
	}

	cout << "========================================TIC-TAC-TOE========================================\n\n";

	board(b, r, c); // displaying the board

	cout << "\n\nPlayer1 will be represented by the symbol : \"X\"\n ";
	cout << "\nPlayer2 will be represented by the symbol : \"O\"\n\n ";

	char p1, p2;

	while (!wcheck(b, r, c)) // winner/draw checker loop
	{

		cout << "\n\nPlayer1 will input the index where they want to insert their symbol: ";
		cin >> p1;

		while (!d1check(b, r, c, p1) || (p1 < '1' || p1 > '9')) // input validation
		{
			cout << "\nPlease enter another index: ";
			cin >> p1;
		}

		board(b, r, c);

		cout << "\n\nPlayer2 will input the index where they want to insert their symbol: ";
		cin >> p2;

		while (!d2check(b, r, c, p2) || (p2 < '1' || p2 > '9')) // input validation
		{
			cout << "\nThis Index is already occupied. Please enter another index: ";
			cin >> p2;
		}

		board(b, r, c);
	}

	if (wcheck(b, r, c) == 1)
	{
		cout << "\n\n\n========================================Player1 is the WINNER========================================\n";
		cout << "========================================THANKS FOR PLAYING========================================\n";
	}
	if (wcheck(b, r, c) == 2)
	{
		cout << "\n\n\n========================================Player2 is the WINNER========================================\n";
		cout << "========================================THANKS FOR PLAYING========================================\n";
	}
	if (wcheck(b, r, c) == 9) // draw count
	{
		cout << "\n\n\n========================================IT'S A DRAW========================================\n";
		cout << "========================================THANKS FOR PLAYING========================================\n";
	}
}

void board(char **b, int r, int c) // function to display the board
{
	cout << "|     |     |     |\n";
	cout << "|  " << *(*(b + 0) + 0) << "  |  " << *(*(b + 0) + 1) << "  |  " << *(*(b + 0) + 2) << "  |\n";
	cout << "|_____|_____|_____|\n";
	cout << "|     |     |     |\n";
	cout << "|  " << *(*(b + 1) + 0) << "  |  " << *(*(b + 1) + 1) << "  |  " << *(*(b + 1) + 2) << "  |\n";
	cout << "|_____|_____|_____|\n";
	cout << "|     |     |     |\n";
	cout << "|  " << *(*(b + 2) + 0) << "  |  " << *(*(b + 2) + 1) << "  |  " << *(*(b + 2) + 2) << "  |\n";
	cout << "|     |     |     |\n";
}

bool wcheck(char **b, int r, int c) // to check the winner or draw
{
	bool flag = 0;
	char alpha = '1';
	int count = 1;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (*(*(b + i) + j) != alpha++) // checks if any number is left or any empty space
			{
				count++; // increments if the space is filled
			}
		}
		if ((*(*(b + i) + 0) == *(*(b + i) + 1) && *(*(b + i) + 0) == *(*(b + i) + 2) && *(*(b + i) + 0) == 'X') || (*(*(b + 0) + i) == *(*(b + 1) + i) && *(*(b + 0) + i) == *(*(b + 2) + i) && *(*(b + i) + 0) == 'X')) // player1 winning condition
		{
			flag = 1;
			return flag;
		}
		if ((*(*(b + i) + 0) == *(*(b + i) + 1) && *(*(b + i) + 0) == *(*(b + i) + 2) && *(*(b + i) + 0) == 'O') || (*(*(b + 0) + i) == *(*(b + 1) + i) && *(*(b + 0) + i) == *(*(b + 2) + i) && *(*(b + i) + 0) == 'O')) // player2 winning condition
		{
			flag = 2;
			return flag;
		}
	}

	if (count == 9) // if match has been drawn
	{
		return count;
	}
	else
	{
		return flag;
	}
}

bool d1check(char **b, int r, int c, char p) // checks if the index is empty and then inserts the symbol
{
	bool flag = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (*(*(b + i) + j) == p) // if the index was empty or had a number
			{
				*(*(b + i) + j) = 'X'; // inserting for player1

				flag = 1;
			}
		}
	}

	return flag;
}

bool d2check(char **b, int r, int c, char p) // checks if the index is empty and then inserts the symbol
{
	bool flag = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (*(*(b + i) + j) == p) // if the index was empty or had a number
			{
				*(*(b + i) + j) = 'O'; // inserting for player1

				flag = 1;
			}
		}
	}

	return flag;
}