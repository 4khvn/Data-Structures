#include<iostream>
using namespace std;
#define MAX 10
class Stack
{
private:
	int top;
	int arr[MAX];
public:
	Stack()
	{
		top = -1;
	}
	int push(int a)
	{
		if (top >= 9)
		{
			cout << "Stack full";
			return 0;
		}
		else
		{
			top++;
			arr[top] = a;
		}
	}
	int pop()
	{
		if (top < 0)
		{
			cout << "Stack empty";
			return 0;
		}
		else
		{
			return arr[top--];
		}
	}
	int peek()
	{
		if (top < 0)
		{
			cout << "Stack empty";
			return 0;
		}
		else
		{
			return arr[top];
		}
	}
	bool Isempty()
	{
		if (top != -1)
		{
			return true;
	}
		else
		{
			return false;
		}
	}
	void display()
	{
		if (top < 0)
		{
			cout << "Stack empty";
		}
		int x = top;
		while (x > -1)
		{
			cout << arr[x] << endl;
			x--;
		}
	}
};
int main()
{
	Stack obj;
	for (int i = 0; i < MAX;i++)
	{
		obj.push(i);
	}
	obj.display();
	while (!obj.Isempty())
	{
		obj.pop();
	}
}