#include<iostream>
using namespace std;
#define MAX 10
class Stack
{
private:
	int top;
	int arr[MAX] = { -1 };
public:
	Stack()
	{
		top = -1;
	}
	void push1(int a)
	{
		Stack* obj2 = new Stack;
		if (top == -1)
		{
			push(a);
		}
		else
		{
			if (top > -1)
			{
				while (top > -1)
				{
					int temp = pop();
					obj2->push(temp);
				}
			}
			push(a);
		}
		
		if (obj2->top > -1)
		{
			while (obj2->top > -1)
			{
				int temp = obj2->pop();;
				push(temp);
			}
		}
		delete[] obj2;
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
			int a = arr[top];
			top--;
			return a;
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
	for (int i = 0; i < 5; i++)
	{
		obj.push1(i);
	}
	obj.pop();
	obj.display();
}
