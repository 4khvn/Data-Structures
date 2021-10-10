#include<iostream>
using namespace std;
bool Check(int ** arr,int row,int col,int size)
{ 
	for (int i = 0; i < row; i++)
	{
		if (arr[i][col] == 1)
			return false;
	}
	int i = row;
	int j = col;
	while (i >= 0 && j >= 0)
	{
		if (arr[i][j] == 1) {
			return false;
		}
		i--;
		j--;
	}
	i = row;
	j = col;
	while (i >= 0 && j < size)
	{
		if (arr[i][j] == 1)
		{
			return false;
		}
		i--;
		j++;
	}
	return true;
} 
bool queencheck(int** arr, int row, int size)
{
	if (row >= size)
	{
		return true;
	}
	for (int col = 0; col < size; col++)
	{
		if (Check(arr, row, col, size))
		{
			arr[row][col] = 1;
		
		if (queencheck(arr, row + 1,size))
		{
			return true;
		}
		}
		arr[row][col] = 0;
	}
	return false;
}
int main()
{
	cout << "Enter size of array" << endl;
	int size;
	cin >> size;
	int** arr = new int* [size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = 0;
		}
	}
	if (queencheck(arr, 0, size))
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
}
//Nth Queen By Muhammad Anas Khann. 
