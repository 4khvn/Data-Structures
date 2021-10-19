#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	node* next1;
public:
	node()
	{
		data = 0;
		next = NULL;
		next1 = NULL;
	}
	node(int a)
	{
		data = a;
	}
};
class handle
{
public:
	node* head;
	node* tail;
	node* temp;
	handle()
	{
		head = NULL;
		tail = NULL;
	}
	void insertnode(int a)
	{
		node* obj = new node(a);
		if (head == NULL)
		{
			head = obj;
			tail = head;
			return;
		}
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = obj;
	}
	void add()
	{
		temp = head;
		node* temp1;
		temp1 = head;
		while (temp1 != NULL)
		{
			temp1 = temp1->next;
			if (temp1 != NULL)
			{
				temp1->next1 = temp;
				
			}
			temp = temp->next;
		}
	}
	void loopfind()
	{
		static int count = 0;
		temp = head;
		node* temp1 = head;
		while (temp != NULL)
		{
			if (temp != NULL)
			{
				temp1 = temp;
				while (temp1 != NULL)
				{
					temp1 = temp1->next;
					if (temp1 != NULL)
					{
						if (temp1->next1 == temp)
						{
							count = count +1;
						}
						break;
					}
				}
			}
			temp = temp->next;
		}
		cout << endl << "Loops are : " << count;
	}
	void display()
	{
		temp = head;
		while (temp != NULL)
		{

			cout << temp->data;
			temp = temp->next;
			if (temp != NULL)
			{
				cout << temp->next1->data;
			}
		}
	}
		
		
		
	
};

int main()
{
	handle obj;
	cout << "Enter number of nodes" << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cout << "Enter value " << endl;
		cin >> a;
		obj.insertnode(a);
	}
	obj.add();
	obj.display();
	obj.loopfind();
}
