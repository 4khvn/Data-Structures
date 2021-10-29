#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
public:
	node() {}
	node(int a)
	{
		next = NULL;
		data = a;

	}
};
class handle
{
public:
	node* head;
	node* temp;
public:
	handle()
	{
		head = NULL;
		
	}
	void push(int a)
	{
		node* obj = new node(a);
		node* temp = head;
		head = obj;
		head->next = temp;
	}
	int pop()
	{
		if (head == NULL)
		{
			cout << "Stack empty";
		}
		else
		{
			temp = head;
			head = head->next;
			return temp->data;
		}
	}
	 int peek()
	{
		temp = head;
		
			if (temp != NULL)
			{
				return temp->data;
			}
		
	}
	 void Display()
	 {
		 temp = head;
		 if (head == NULL)
		 {
			 cout << " Stack is empty";
		 }
		 else
		 {
			 while (temp != NULL)
			 {
				 cout << temp->data;
				 temp = temp->next;
			 }
		 }
	 }
	 bool Isempty()
	 {
		 if (head != NULL)
		 {
			 return true;

		 }
		 else
		 {
			 return false;
		 }
	 }
};
int main()
{
	handle obj;
	for (int i = 0; i < 10; i++)
	{
		obj.push(i);
	}
	obj.Display();
	while (!obj.Isempty())
	{
		int x =obj.pop();
	}
}
