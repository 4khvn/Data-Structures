#include<iostream>
using namespace std;
class stack
{
private:
	int size;
	 int curr = -1 ;
	 char* stack1;
public:
	stack()
	{}
	stack(int x)
	{
		size = x;
		
		stack1 = new char[size];
	}
	void push(char a)
	{
		if (curr == size)
		{
			cout << "Stack full";
		}
		else
		{
			curr++;
			stack1[curr] = a;
		}
	}
	int pop()
	{
		if (curr < 0)
		{
			cout << "Stackl empty";
		}
		else
		{
			return stack1[curr--];
		}
	}
	int peek()
	{
		if (curr < 0)
		{
			cout << "Stack empty";
		}
		else
		{
			return stack1[curr];
		}
	}
	int priority(char a)
	{
		if (a == '^')
		{
			return 3;
		}
		if (a == '/' || a == '*')
		{
			return 2;

		}
		if (a == '+' || a == '-')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void infixToPostfix(string infix)
	{
		string postfix;
		int x = infix.length();
		for (int i = 0; i < x; i++)
		{
			char a = infix[i];
			if (a >= 'a' && a <= 'z')
			{
				postfix += a;
			}
			else if (a == '(')
			{
				push(a);

			}

			else if (a == ')')
			{
				while (peek() != '(')
				{
					postfix += peek();
					pop();
				}
				pop();

			}
			else
			{
				while (curr >= 0 && (priority(a) < priority(peek()) || priority(a) == priority(peek())))
				{
					postfix += peek();
					pop();
				}
				push(a);

			}
		}
		while (curr >= 0)
		{
			postfix += peek();
			pop();
		}
		cout << postfix << endl;

	}
};
int main()
{
	string infix = "a+b*(c^d-e)^(f+g*h)-i";
	int x = infix.length();
	stack obj(x);
	obj.infixToPostfix(infix);
	return 0;
}

