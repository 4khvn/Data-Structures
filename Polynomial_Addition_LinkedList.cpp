#include<iostream>
using namespace std;
static int qaq = 0;

class node
{
public:
	node* next;
	int data;
	char variable;
	int power;
public:
	node()
	{}
	node(int a,char b,int c)
	{
		next = NULL;
		data = a;
		variable = b;
		power = c;
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
		tail = NULL;
	}
	void sort()
	{
		temp = head;
		node* temp1 = head;
		if (temp == NULL)
		{
			return;
		}
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
						if (temp1->variable < temp->variable)
						{
							int a, c;
							char b;
							a = temp1->data;
							b = temp1->variable;
							c = temp1->power;
							temp1->data = temp->data;
							temp1->variable = temp->variable;
							temp1->power = temp->power;
							temp->data = a;
							temp->variable = b;
							temp->power = c;
							
						}
						else if (temp1->variable == temp->variable)
						{
							if (temp1->power < temp->power)
							{
								int a, c;
								char b;
								a = temp1->data;
								b = temp1->variable;
								c = temp1->power;
								temp1->data = temp->data;
								temp1->variable = temp->variable;
								temp1->power = temp->power;
								temp->data = a;
								temp->variable = b;
								temp->power = c;
								
							}
						}
					}
					
				}
			}
			temp = temp->next;
		}
	}
	void insert1(int a, char b, int c)
	{
		node* obj = new node(a, b, c);
		if (head == NULL)
		{
			head = obj;
			tail = obj;
			return;
		}
		while (tail->next != NULL)
		{

			tail = tail->next;
		}
		tail->next = obj;
		
	}
	void insert(int a,char b,int c)
	{
		node* obj = new node(a, b, c);
		if (head == NULL)
		{
			head = obj;
			tail = obj;
			return;
		}
		while (tail->next != NULL)
		{
			
			tail = tail->next;
		}
		tail->next = obj;
		sort();
	}
	void display()
	{
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << temp->variable << temp->power << endl;
			temp = temp->next;
		}
	}
};
void Addition(node * head1,node * head2)
{
	handle obj3;
	node * temp1 = head1;
	node* temp2 = head2;
	while ( temp2 != NULL || temp1 != NULL)
	{
		if (temp1 != NULL && temp2 != NULL)
		{
			if (temp1->variable == temp2->variable)
			{
				if (temp1->power == temp2->power)
				{
					int a = (temp1->data) + (temp2->data);
					char b = temp1->variable;
					int c = temp1->power;
					obj3.insert1(a, b, c);
					qaq++;

					temp1 = temp1->next;
					temp2 = temp2->next;
				}
				else if (temp1->power < temp2->power)
				{
					int a = temp1->data;
					char b = temp1->variable;
					int c = temp1->power;
					obj3.insert1(a, b, c);
					qaq++;
					temp1 = temp1->next;
				}
				else  if (temp2->power < temp1->power)
				{
					int a = temp2->data;
					char b = temp2->variable;
					int c = temp2->power;
					obj3.insert1(a, b, c);
					qaq++;

					temp2 = temp2->next;
				}

			}

			else if (temp1->variable < temp2->variable)
			{
				int a = temp1->data;
				char b = temp1->variable;
				int c = temp1->power;
				obj3.insert1(a, b, c);
				qaq++;

				temp1 = temp1->next;
			}
			else if (temp2->variable < temp1->variable)
			{
				int a = temp2->data;
				char b = temp2->variable;
				int c = temp2->power;
				obj3.insert1(a, b, c);
				qaq++;

				temp2 = temp2->next;
			}
		}
			else if(temp1 == NULL || temp2 == NULL)
			{
				if (temp1 != NULL)
				{
					int a = temp1->data;
					char b = temp1->variable;
					int c = temp1->power;
					obj3.insert1(a, b, c);
					qaq++;

					temp1 = temp1->next;
				}
				if (temp2 != NULL)
				{
					int a = temp2->data;
					char b = temp2->variable;
					int c = temp2->power;
					obj3.insert1(a, b, c);
					qaq++;

					temp2 = temp2->next;
				}
			}
		

}
	cout << qaq << endl;
	node* temp4 = obj3.head;
	while (temp4 != NULL)
	{
			cout << temp4->data << " " << temp4->variable << " " << temp4->power << endl;
			temp4 = temp4->next;
	}

	
	
}

int main()
{
	handle obj;
	int num;
	int data, power;
	char variable;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> data >> variable >> power;
		obj.insert(data, variable, power);
	}
	//obj.display();
	handle obj2;
	int num1;
	int data1, power1;
	char variable1;
	cin >> num1;
	for (int i = 0; i < num1; i++)
	{
		cin >> data1 >> variable1 >> power1;
		obj2.insert(data1, variable1, power1);
	}
	//obj2.display();
	Addition(obj.head, obj2.head);
	
}
