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
	void sort()
	{
		Stack* obj2 = new Stack;
		while (top >= 0)
		{
			int temp = pop();
			if (obj2->top < 0)
			{
				obj2->push(temp);
			}
			else
			{
				int temp1 = obj2->peek();
				if (temp < temp1)
				{
					while (temp < obj2->peek())
					{
						int fwf;
						fwf = obj2->pop();
						push(fwf);
					}
					
				}
				obj2->push(temp);

			}
		}
		obj2->display();
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
			cout << arr[x] << " ";
			x--;
		}
		cout << endl;
	}
};
int main()
{
	Stack obj;
	obj.push(4);
	obj.push(9);
	obj.push(2);
	obj.push(6);
	obj.push(22);
	obj.push(7);
	obj.push(0);
	cout << "before sorting: " << endl;
	obj.display();
	cout << "After sorting: " << endl;
	obj.sort();


}
