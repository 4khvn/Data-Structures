#include<iostream>
using namespace std;
static int arrindex = -1;

int main()
{
	int arr[][2] = { {0,1},{0,2},{1,0},{1,3},{2,0},{2,3},{3,1},{3,5},{4,2},{4,5},{5,3},{5,4} };
	int** array = new int* [6];
	for (int i = 0; i < 6; i++)
	{
		array[i] = new int[6];
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			array[i][j] = 0;
		}

	}
	
	for (int i = 0; i < 6; i++)
	{
	
		for (int j = 0; j < 6; j++)
		{
			
			for (int k = 0; k < 12; k++)
			{
				int a = arr[k][0];
					if (i == a)
					{
						int ba = arr[k][1];
						if (j == ba)
						{
							array[i][j] = 1;
						}
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
