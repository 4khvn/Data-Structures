#include<iostream>
using namespace std;
int arr[4][4] = {0};
int func( int a[4][4], int row, int column, int max)
{
	
	bool flag = false;
	cout << row << " " << column << endl;	
	arr[row][column] = 1;
	if (row == max && column == max)
	{
		cout << "maze destination " << endl << endl << endl;
		for(int i=0;i<=max;i++)
		{
			for(int j=0;j<=max;j++)
			{
				cout << arr[i][j];
			}
			cout << endl;
		}
		exit(1);
	}
	if(a[row][column+1] == 1 && column != max)
	{
		
		flag = func(a,row,column+1,max);
	}
	if(a[row+1][column] == 1 && row !=max)
	{
		
		flag = func(a,row+1,column,max);
	}
	arr[row][column] = 0;
	return flag;

}
int main()
{
	int arr[4][4] = { {1,0,0,0},{1,1,1,0},{0,1,0,0},{1,1,1,1} };
	int array[4][4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << " " << arr[i][j];
		}
		cout << endl;
	}
	func(arr, 0, 0, 3);
}
