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
		cout << endl;
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
		cout << "Enter value you want to swap" << endl;
		int a, b;
		cin >> a >> b;
		temp = head;
		node* temp1 = head;
		while (temp != NULL)
		{
			if (temp != NULL)
			{
				if (temp->data == a)
				{
					goto hh;
				}
			}
			temp = temp->next;
		}
	hh:
		while (temp1 != NULL)
		{
			if (temp1 != NULL)
			{
				if (temp1->data == b)
				{
					goto hg;
				}
			}
			temp1 = temp1->next;
		}
	hg:
		if (temp == head)
		{
			
			temp1 = head;
			while (temp1 != NULL)
			{
				if (temp1 != NULL)
				{
					if (temp->next != NULL)
					{
						if (temp1->next->data == b)
						{
							goto an;
						}
					}
				}
				temp1 = temp1->next;
			}
		an:
			node* temp2 = temp->next;
			node* temp3 = temp1->next;
			node* temp4 = temp3->next;
			temp1->next = temp;
			head = temp3;
			temp3->next = temp2;
			temp->next = temp4;
			
		}
		else if (temp1 == head)
		{

			temp = head;
			while (temp != NULL)
			{
				if (temp != NULL)
				{
					if (temp->next != NULL)
					{
						if (temp->next->data == a)
						{
							goto aw;
						}
					}
				}
				temp = temp->next;
			}
		aw:
			node* temp2 = temp1->next;
			node* temp3 = temp->next;
			node* temp4 = temp3->next;
			temp->next = temp1;
			head = temp3;
			temp3->next = temp2;
			temp1->next = temp4;

		}
		else if (temp->next == temp1)
		{
			temp = head;
			node* temp1 = head;
			while (temp != NULL)
			{
				if (temp != NULL)
				{
					if (temp->next->data == a)
					{
						goto aa;
					}
				}
				temp = temp->next;
			}
		aa:
			while (temp1 != NULL)
			{
				if (temp1 != NULL)
				{
					if (temp1->data == b)
					{
						goto ab;
					}
				}
				temp1 = temp1->next;
			}
		ab:
			node* temp2 = temp->next;
			node* temp3 = temp1->next;
			temp->next = temp1;
			temp1->next = temp2;
			temp2->next = temp3;
		}
		else if (temp1->next == temp)
		{
			temp = head;
			node* temp1 = head;
			while (temp1 != NULL)
			{
				if (temp1 != NULL)
				{
					if (temp1->data == a)
					{
						goto ca;
					}
				}
				temp1 = temp1->next;
			}
		ca:
			while (temp != NULL)
			{
				if (temp != NULL)
				{
					if (temp->next != NULL)
					{
						if (temp->next->data == b)
						{
							goto cb;
						}
					}
				}
				temp = temp->next;
			}
		cb:
			node* temp2 = temp->next;
			node* temp3 = temp1->next;
			temp->next = temp1;
			temp1->next = temp2;
			temp2->next = temp3;
		}
		else
		{
			temp = head;
			node* temp1 = head;

			while (temp != NULL)
			{

				if (temp != NULL)
				{
					if (temp->next != NULL)
					{
						if (temp->next->data == a)
						{
							goto here;
						}
					}
				}
				temp = temp->next;
			}
		here:
			node* temp2 = NULL;
			temp2 = temp->next;
			node* temp5 = NULL;
			temp5 = temp2->next;

			while (temp1 != NULL)
			{

				if (temp1 != NULL)
				{
					if (temp1->next != NULL)
					{
						if (temp1->next->data == b)
						{
							goto here1;
						}
					}
				}
				temp1 = temp1->next;
			}

		here1:
			node* temp3 = NULL;
			temp3 = temp1->next;
			node* temp4 = NULL;
			temp4 = temp3->next;
			temp->next = temp3;
			temp3->next = temp5;
			temp1->next = temp2;
			temp2->next = temp4;

		}
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
	node* mergeboth(node*first,node* second)
	{
		node* answer = NULL;
		if (first == NULL)
		{
			return second;
		}
		if (second == NULL)
		{
			return first;
		}
		if (first->data <= second->data)
		{
			answer = first;
			answer->next = mergeboth(first->next, second);
		}
		if (second->data <= first->data)
		{
			answer = second;
			answer->next = mergeboth(first, second->next);
		}
		return answer;
	}
	void FindMiddle(node * cur,node ** first,node** second)
	{
		node* fast;
		node* slow;
		slow = cur;
		fast = cur->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*first = cur;
		*second = slow->next;
		slow->next = NULL;
	}
	void mergesorting(node ** head)
	{
		node* curr = *head;
		node* first;
		node* second;
		if (curr == NULL || curr->next == NULL)
		{
			return;
		}
		FindMiddle(curr, &first, &second);
		mergesorting(&first);
		mergesorting(&second);
		*head = mergeboth(first, second);
	}

	node* mergesort(node* head)
	{
		mergesorting(&head);
		return head;
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
	system("CLS");
	cout << "Please select your desired function of linked list: " << endl << "1. delete node" << endl << "2. swap element" << endl << "3. swap node" << endl << "4. prepend node" << endl << "5. append node" << endl << "6. insert node between" << endl << "7. reverse list" << endl << "8. merge sort" << endl;
	int qw;
	cin >> qw;
	switch (qw)
	{
	case 1:
	{
		obj.displaylist();
		obj.deletenode();
		obj.displaylist();
	}
	case 2:
	{
		obj.displaylist();
		obj.swapelement();
		obj.displaylist();
	}
	case 3:
	{
		obj.displaylist();
		obj.swapnode();
		obj.displaylist();
	}
	case 4:
	{
		obj.displaylist();
		obj.prependnode();
		obj.displaylist();
	}
	case 5:
	{
		obj.displaylist();
		obj.appendnode();
		obj.displaylist();
	}
	case 6:
	{
		obj.displaylist();
		obj.insernodeinbetween();
		obj.displaylist();
	}
	case 7:
	{
		obj.displaylist();
		obj.reverselist();
		obj.displaylist();
	}
	case 8:
	{
		obj.displaylist();
		obj.mergesort(obj.head);
		obj.displaylist();
	}
	}
}
