#include "pch.h"
#include <iostream>
using namespace std;

char player = 'X';
char matrix[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

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

void TogglePlayer() 
{
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
}

int CheckWin() 
{
	if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X') return 1;
	else if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X') return 1; 
	else if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X') return 1;	
	
	else if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X') return 1;
	else if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X') return 1; 
	else if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X') return 1;

	else if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O') return 2;
	else if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O') return 2;
	else if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O') return 2;

	else if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O') return 2;
	else if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O') return 2;
	else if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O') return 2;

	else return 0;


}

int main()
{
	Draw();
	while (1) 
	{
		int input = Input();
		Draw();
		if (input == 0)
		{
			int win = CheckWin();
			if (win == 1) { cout << "X Wins!" << endl; break; }
			else if (win == 2) { cout << "O Wins!" << endl; break; }
			else TogglePlayer(); 
		}
		else cout << "Invalid Move, Try Again..." << endl;
	}
	system("pause");
}