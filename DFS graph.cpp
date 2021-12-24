#include<iostream>
#include<string>
using namespace std;
static int arrindex = 0;
#define MAX 5
class Stack
{
private:
	int top;
	int arr1[MAX] = { 0 };
public:
	Stack()
	{
		top = -1;
	}
	int push(int a)
	{
		if (top >= 4)
		{
			cout << "Stack full";
			return 0;
		}
		else
		{
			top++;
			arr1[top] = a;
		}
	}
	string pop()
	{
		if (top < 0)
		{
			cout << "Stack empty";
			return 0;
		}
		else
		{
			string str;
			str = to_string(arr1[top]);
			top = top - 1;
			return str;
		}
	}
	string peek()
	{
		if (top < 0)
		{
			cout << "Stack empty";
			return 0;
		}
		else
		{
			return 0;
		}
	}
	bool validcheck(int a)
	{
		for (int i = 0; i <= top; i++)
		{
			if (arr1[i] == a)
			{
				return false;
			}
		}
		return true;
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
			cout << arr1[x] << endl;
			x--;
		}
	}
	string allempty()
	{
		string str;
		while (Isempty())
		{
			str += pop();
		}
		return str;
	}
};
class node
{
public:
	int data;
	bool visited = false;
	node* next;
	node()
	{
		data = 0;
		next = NULL;
	}
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
	handle() {
		head = NULL;
		tail = NULL;
	}
	void insert(int a)
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

};
int main()
{
	string dfs;
	int arr[][2] = { {0,3},{0,2},{0,1},{1,2},{2,4} };;
	handle* array = new handle[6];
	Stack obj1;
	for (int i = 0; i <= 5; i++)
	{
		bool check = false;
		for (int k = 0; k < 3; k++)
		{
			if (array[k].head != NULL)
			{
				if (array[k].head->data == arr[i][0])
				{
					check = true;
					break;
				}
			}
		}
		if (check == false)
		{
			handle obj;
			obj.insert(arr[i][0]);
			array[arrindex].head = obj.head;
			arrindex++;
			for (int j = 0; j <= 5; j++)
			{
				if (arr[j][0] == obj.head->data)
				{
					int x = arr[j][1];
					obj.insert(x);
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		auto ptr = array[i].head;
		while (ptr != NULL)
		{
			cout << ptr->data << " ->";
			ptr = ptr->next;
		}
		cout << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		auto ptr = array[i].head;
		if (obj1.validcheck(ptr->data))
		{
			obj1.push(ptr->data);
		}
		array[i].head->visited = true;
		dfs += obj1.pop();
		while (ptr != NULL)
		{
			ptr = ptr->next;
			if (ptr != NULL)
			{
				if (obj1.validcheck(ptr->data))
				{
					obj1.push(ptr->data);
				}
			}
			
		}
		
		cout << endl;
	}
	dfs += obj1.allempty();
	cout << dfs;
}
