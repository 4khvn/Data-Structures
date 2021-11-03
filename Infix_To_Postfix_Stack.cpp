#include<iostream>
using namespace std;
static int curr = -1;
char stack[20];
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
			curr++;
			stack[curr] = a;
			
		}
		
		else if (a == ')')
		{
			while (stack[curr] != '(')
			{
				postfix += stack[curr];
				stack[curr] = 0;
				curr--;
			}
			curr--;
		
		}
		else
		{
		while (curr >= 0 && (priority(a) < priority(stack[curr]) || priority(a) == priority(stack[curr])))
		{
			postfix += stack[curr];
			stack[curr] = 0;
			curr--;
		}
			curr++;
			stack[curr] = a;
			
		}
	}
	while (curr >= 0)
	{
		postfix += stack[curr];
		stack[curr] = 0;
		curr--;
	}
	cout << postfix << endl;
	
}
int main()
{
	string infix = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(infix);
	return 0;
}
