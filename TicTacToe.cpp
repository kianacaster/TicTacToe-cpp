// Tic Tac Toe by Kian Acaster

#include "pch.h" // Only needed if using Visual Studio
#include <iostream>
using namespace std;

char player = 'X'; /
char matrix[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' }; // The grid which the game is played on

// Display the grid
void Draw() 
{
	system("CLS");
	cout << "Tic Tac Toe" << endl;
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

// Gets input from the player and maps that to a space on the grid. 
// The 'if' statements check to see if the selected space is filled or not
// If the space is filled, the move is invalid and doesn't count.
// Return of 0 = Valid Move, 1 = Invalid Move
int Input() 
{
	int a;
	cout << "Press the number of the square you want...";
	cin >> a;

	if (a == 1)
		if (matrix[0][0] != 'X' && matrix[0][0] != 'O') matrix[0][0] = player;
		else return 1;
	else if (a == 2)
		if (matrix[0][1] != 'X' && matrix[0][1] != 'O') matrix[0][1] = player;
		else return 1;
	else if (a == 3)
		if (matrix[0][2] != 'X' && matrix[0][2] != 'O') matrix[0][2] = player;
		else return 1;
	else if (a == 4)
		if (matrix[1][0] != 'X' && matrix[1][0] != 'O') matrix[1][0] = player;
		else return 1;
	else if (a == 5)
		if (matrix[1][1] != 'X' && matrix[1][1] != 'O') matrix[1][1] = player;
		else return 1;
	else if (a == 6)
		if (matrix[1][2] != 'X' && matrix[1][2] != 'O') matrix[1][2] = player;
		else return 1;
	else if (a == 7)
		if (matrix[2][0] != 'X' && matrix[2][0] != 'O') matrix[2][0] = player;
		else return 1;
	else if (a == 8)
		if (matrix[2][1] != 'X' && matrix[2][1] != 'O') matrix[2][1] = player;
		else return 1;
	else if (a == 9)
		if (matrix[2][2] != 'X' && matrix[2][2] != 'O') matrix[2][2] = player;
		else return 1;
	return 0;
}

// Switches turns; if the last turn was X, change to O - vice versa.
void TogglePlayer() 
{
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
}

// Checks if there is a line of 3 from either the Xs or Os - if so, returns who won.
int CheckWin() 
{
	// Horizontal
	if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X') return 1;
	else if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X') return 1; 
	else if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X') return 1;	
	
	else if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X') return 1;
	else if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X') return 1; 
	else if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X') return 1;
	
	// Vertical 
	else if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O') return 2;
	else if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O') return 2;
	else if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O') return 2;

	else if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O') return 2;
	else if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O') return 2;
	else if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O') return 2;
	
	// Diagonal
	else if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X') return 1;
	else if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X') return 1;
	
	else if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O') return 2;
	else if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O') return 2;

	else return 0;


}

int main()
{
	Draw();
	while (1) 
	{
		int input = Input();
		Draw();
		if (input == 0) // If there's a valid input
		{
			int win = CheckWin(); // See if this move results in a win
			if (win == 1) { cout << "X Wins!" << endl; break; } // If X won
			else if (win == 2) { cout << "O Wins!" << endl; break; } // If O won
			else TogglePlayer(); // If there's no win
		}
		else cout << "Invalid Move, Try Again..." << endl; // If the input was an invalid move
	}
	system("pause");
}
