/*You all are very much familiar with the game of Tic-Tac-Toe. It is a finite step alternating move two players game. Given a partial board from the game we can easily decide what will be the outcome of the game. In this problem, you are given an intermediate board from a game and you should decide whether the game will be a draw or a win for either player. Input for the same will be a 3X3 matrix of values 0,1, and 2. Where 0 represents an empty cell, 1 and 2 represent player 1 or player 2 respectively. You can assume that both players are using their optimal strategies in the game. 

Input will be a 3 X 3 matrix 

1 0 2
1 1 0
0 0 0 

The output will be an integer value from {-1, 0,1 and 2} where -1 represents invalid board, 0 means a draw and 1 or 2 represents the winning of Player 1(X) or Player 2 (O).*/
#include<iostream>
using namespace std;
static int roww = 0;
static int coll = 0;
void turns(int** a, int turn, int opponent, int row, int col)
{

	for (int i = 0; i < 3; i++)
	{
		if (a[0][i] == 1)
		{

			if (a[1][i] == 1 && a[2][i] == 1)
			{
				cout << "1";
				exit(0);
			}

			if ((i - 2) >= 0)
			{
				if (a[1][i - 1] == 1 && a[2][i - 2] == 1)
				{
					cout << "1";
					exit(0);
				}
			}
			if ((i + 2) < 3)
			{
				if (a[1][i + 1] == 1 && a[2][i + 2] == 1)
				{
					cout << "1";
					exit(0);
				}
			}
		}
		if (a[0][i] == 2)
		{

			if (a[1][i] == 2 && a[2][i] == 2)
			{
				cout << "2";
				exit(0);
			}

			if ((i - 2) >= 0)
			{
				if (a[1][i - 1] == 2 && a[2][i - 2] == 2)
				{
					cout << "2";
					exit(0);
				}
			}
			if ((i + 2) < 3)
			{
				if (a[1][i + 1] == 2 && a[2][i + 2] == 2)
				{
					cout << "2";
					exit(0);
				}
			}

		}

	}

	for (int j = 0; j < 3; j++)
	{
		if (a[j][0] == 1)
		{

			if (a[j][1] == 1 && a[j][2] == 1)
			{
				cout << "1";
				exit(0);
			}

		}
		if (a[j][0] == 2)
		{
			if (a[j][1] == 2 && a[j][2] == 2)
			{
				cout << "2";
				exit(0);
			}

		}

	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)

		{
			if (a[i][j] == turn)
			{
				if ((j + 2) < 3)
				{
					if (a[i][j + 1] == 0 && a[i][j + 2] == turn)
					{
						a[i][j + 1] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((j + 2) < 3)
				{
					if (a[i][j + 1] == turn && a[i][j + 2] == 0)
					{
						a[i][j + 2] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i - 2) >= 0 && (j - 2) >= 0)
				{
					if (a[i - 1][j - 1] == turn && a[i - 2][j - 2] == 0)
					{
						a[i - 1 - 1][j - 1 - 1] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i + 2) < 3 && (j + 2) < 3)
				{
					if (a[i + 1][j + 1] == turn && a[i + 2][j + 2] == 0)
					{
						a[i + 1 + 1][j + 1 + 1] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i - 2) >= 0 && (j + 2) < 3)
				{
					if (a[i - 1][j + 1] == turn && a[i - 2][j + 2] == 0)
					{
						a[i - 1 - 1][j + 1 + 1] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i + 2) < 3 && (j - 2) >= 0)
				{
					if (a[i + 1][j - 1] == turn && a[i + 2][j - 2] == 0)
					{
						a[i + 1 + 1][j - 1 - 1] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i + 2) < 3)
				{
					if (a[i + 1][j] == turn && a[i + 2][j] == 0)
					{
						a[i + 1 + 1][j] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i - 2) >= 0 && (j - 2) >= 0)
				{
					if (a[i - 1][j - 1] == 0 && a[i - 2][j - 2] == 0)
					{
						a[i - 1][j - 1] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i + 2) < 3 && (j + 2) < 3)
				{
					if (a[i + 1][j + 1] == 0 && a[i + 2][j + 2] == 0)
					{
						a[i + 1][j + 1] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i - 2) >= 0 && (j + 2) < 3)
				{
					if (a[i - 2][j + 2] == turn && a[i - 1][j + 1] == 0)
					{
						a[i - 1][j + 1] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i + 2) < 3 && (j - 2) >= 0)
				{
					if (a[i + 2][j - 2] == turn && a[i + 1][j - 2] == 0)
					{
						a[i + 1 + 1][j - 1 - 1] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i + 2) < 3)
				{
					if (a[i + 2][j] == turn && a[i + 1][j] == 0)
					{
						a[i + 1][j] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			if (a[i][j] == opponent)
			{
				if ((i - 2) >= 0 && (j - 2) >= 0)
				{
					if (a[i - 1][j - 1] == opponent && a[i - 2][j - 2] == 0)
					{
						a[i - 1 - 1][j - 1 - 1] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i + 2) < 3 && (j + 2) < 3)
				{
					if (a[i + 1][j + 1] == opponent && a[i + 2][j + 2] == 0)
					{
						a[i + 1 + 1][j + 1 + 1] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i - 2) >= 0 && (j + 2) < 3)
				{
					if (a[i - 1][j + 1] == opponent && a[i - 2][j + 2] == 0)
					{
						a[i - 1 - 1][j + 1 + 1] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i + 2) < 3 && (j - 2) >= 0)
				{
					if (a[i + 1][j - 1] == opponent && a[i + 2][j - 2] == 0)
					{
						a[i + 1 + 1][j - 1 - 1] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i + 2) < 3)
				{
					if (a[i + 1][j] == opponent && a[i + 2][j] == 0)
					{
						a[i + 1 + 1][j] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i - 2) >= 0 && (j - 2) >= 0)
				{
					if (a[i - 1][j - 1] == 0 && a[i - 2][j - 2] == opponent)
					{
						a[i - 1][j - 1] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i + 2) < 3 && (j + 2) < 3)
				{
					if (a[i + 1][j + 1] == 0 && a[i + 2][j + 2] == opponent)
					{
						a[i + 1][j + 1] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i - 2) >= 0 && (j + 2) < 3)
				{
					if (a[i - 2][j + 2] == opponent && a[i - 1][j + 1] == 0)
					{
						a[i - 1][j + 1] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i + 2) < 3 && (j - 2) >= 0)
				{
					if (a[i + 2][j - 2] == opponent && a[i + 1][j - 2] == 0)
					{
						a[i + 1 + 1][j - 1 - 1] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				if ((i + 2) < 3)
				{
					if (a[i + 2][j] == opponent && a[i + 1][j] == 0)
					{
						a[i + 1][j] = turn;
						turns(a, opponent, turn, i, j);
					}
				}
				else
				{
					if (i < 3 && j < 3)
					{

						a[roww][coll] = turn;
						if (coll == 2)
						{
							coll = 0;
							roww++;
						}
						else
						{
							coll++;
						}
					}
				}

			}

		}
	}
	cout << "0";
	exit(0);


}
void validcheck(int** a)
{
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] == 1)
			{
				count1++;
			}
			if (a[i][j] == 2)
			{
				count2++;
			}
		}
	}
	if (count1 == 0 && count2 == 0)
	{
		turns(a, 1, 2, 3, 3);
	}
	if (count1 - count2 >= 2 || count2 - count1 >= 2)
	{
		cout << "-1";
		exit(0);
	}
	/*if (count2 >= 2 * (count1))
	{
		cout << "-1";
		exit(0);
	}*/
	if (count1 == count2)
	{
		turns(a, 1, 2, 3, 3);
	}
	if (count1 > count2)
	{
		turns(a, 2, 1, 3, 3);
	}
	if (count2 > count1)
	{
		turns(a, 1, 2, 3, 3);
	}
}
int main()
{
	int** arr = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		arr[i] = new int[3];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
	validcheck(arr);
}
