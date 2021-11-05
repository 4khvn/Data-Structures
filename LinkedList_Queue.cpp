#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node * next;
public:
	node()
	{	}
	node(int a)
	{
		next = NULL;
		data = a;
	}
};
class handle
{
public:
	node* top;
	node * rear;
	node * temp;
public:
	handle()
	{
		top = NULL;
		rear = NULL;
	}
	void enqueu(int a)
	{
		node * obj = new node(a);
		if (top == NULL)
		{
			top = obj;
			rear = top;
			return;
		}
		if (rear->next != NULL)
		{
			rear = rear->next;
		}
		rear->next = obj;
	}
	void dequeue()
	{
		temp = top;
		
		top = top->next;
		delete temp;
	}
	void display()
	{
		temp = top;
		while (temp != NULL)
		{
			cout << temp->data;
			temp = temp->next;
		}
	}

};
int main()
{
	handle obj;
	for (int i = 0; i < 5; i++)
	{
		obj.enqueu(i);
	}
	obj.dequeue();
	obj.dequeue();
	obj.display();
	
}
