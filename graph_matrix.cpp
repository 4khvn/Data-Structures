#include<iostream>
using namespace std;
static int arrindex = -1;

int main()
{
	int arr[][2] = { {0,1},{0,2},{1,0},{1,3},{2,0},{2,3},{3,1},{3,5},{4,2},{4,5},{5,3},{5,4} };
	int** array = new int*[6];
	for (int i = 0; i < 6; i++)
	{
		array[i] = new int[6];
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			array[i][j] = -1;
		}
		
	}
	for (int i = 0; i <= 11; i++)
	{
		int column = 1;
		bool check = false;
		for (int k = 0; k < 6; k++)
		{
			if (array[k] != NULL)
			{
				if (array[k][0] == arr[i][0])
				{
					check = true;
					break;
				}
			}
		}
		if (check == false)
		{
			arrindex++;
			array[arrindex][0] = arr[i][0];
			for (int j = 0; j <=11; j++)
			{
					if (arr[j][0] == array[arrindex][0])
					{
						int x = arr[j][1];
						array[arrindex][column] = x;
						column++;
					}
					
			}
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}

}
