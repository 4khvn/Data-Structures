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
	node* tail;
	node* temp;
public:
	handle()
	{
		head = NULL;
		tail =NULL;
	}
	void insertnode(int a)
	{
		node* obj1 = new node(a);
		if (head == NULL)
		{
			head = obj1;
			tail = head;
			return;
		}
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = obj1;
	}
	void displaylist()
	{
		temp = head;
		while (temp != NULL)
		{

			cout << temp->data;
			temp = temp->next;
		}
	}
	void deletenode()
	{
		int a;
		cout << "enter the value you want to remove" << endl;
		cin >> a;
		temp = head;
		while (temp->next != NULL)
		{
			if (temp->next->data == a)
			{
				node* temp1;
				temp1 = temp->next;
				temp->next = temp->next->next;
				temp = temp->next;

				delete temp1;
				cout << endl << "element deleted!" << endl;
				return;
			}
			temp = temp->next;
		}
	}
	void swapelement()
	{
		int a, b;
		cout << endl << "enter 2 elemnts to be swapped // elements swap" << endl;
		cin >> a >> b;
		temp = head;
		while (temp != NULL)
		{
			if (temp->data == a)
			{
				temp->data = b;
				if (temp->next != NULL)
				{
					temp = temp->next;
				}
			}

			if (temp->data == b)
			{
				temp->data = a;

			}
			temp = temp->next;
		}
	}
	void swapnode()
	{
		int a, b;
		cout << endl << "enter 2 elemnts to be swapped // node swap" << endl;
		cin >> a;
		cin >> b;
		temp = head;
		node* check;
		check = head;
		node* aa = head;
		while (temp != NULL)
		{
			if (temp->next->data == a)
			{
				node* temp1;
				temp1 = temp->next;
				
				while (check != NULL)
				{
					if (check->next->data == b)
					{
						
						node* temp2;
						node* temp3;
						temp2 = check->next;
						temp3 = check;
						temp2->next = temp1->next;
						temp1->next = aa->next->next;
						temp->next = temp2;
						check->next = temp1;
						cout << aa->next->next->data;
						return;
					}
					aa = aa->next;
					check = check->next;
				}
				
			}
			temp = temp->next;
		}
		exit(1);
	}
	void prependnode()
	{
		int a;
		cout << endl << "enter value" << endl;
		cin >> a;
		node* obj = new node(a);
		node* temp = head;
		head = obj;
		head->next = temp;
	}
	void appendnode()
	{
		int a;
		cout << endl << "enter value" << endl;
		cin >> a;
		node* obj = new node(a);
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = obj;
	}
	void insernodeinbetween()
	{
		int a, b;
		cout << endl << "after which element you want to add" << endl;
		cin >> a;
		cout << endl << "enter element you want to add" << endl;
		cin >> b;
		node* obj = new node(b);
		temp = head;
		while (temp != NULL)
		{
			if (temp->data == a)
			{
				obj->next = temp->next;
				temp->next = obj;

				return;
			}
			temp = temp->next;
		}

	}
	void reverselist()
	{
		node* curr;
		node* prev;
		node* next;
		curr = head;
		prev = NULL;
		next = NULL;
		while (curr != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}
};
int main()
{
	int a;
	int size;
	cout << "enter no of elemnts in list" << endl;
	cin >> size;
	handle obj;
	cout << endl << "enter elemnts:" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> a;
		obj.insertnode(a);
	}
	obj.deletenode();
	obj.displaylist();
	obj.swapelement();
	obj.displaylist();
	//obj.swapnode();
	//obj.displaylist();
	obj.prependnode();
	obj.displaylist();
	obj.appendnode();
	obj.displaylist();
	obj.insernodeinbetween();
	obj.displaylist();
	obj.reverselist();
	obj.displaylist();
}
