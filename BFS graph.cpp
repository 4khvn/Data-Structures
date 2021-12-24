#include<iostream>
#include<string>
using namespace std;
static int arrindex = 0;
class queue
{
private:
	int head = 0;
	int temp = 0;
	int array[6] = { 0 };
	int* front;
	int* end;
	int top = 0;
public:
	queue()
	{
		front = NULL;
		end = NULL;
	}
	void Enqueue(int a)
	{
		if (top < 9)
		{
			if (front == NULL)
			{
				array[head] = a;
				front = &array[head];
				end = front;
				top++;
			}
			else
			{
				array[top] = a;
				end = &array[top];
				top++;
			}
		}
		else
		{
			cout << "Array full.";
		}
	}
	string  dequeue()
	{
		string str;
		temp = head;
		str = to_string(array[temp]);
		while (temp != top)
		{
			 
			array[temp] = array[temp + 1];
			temp++;
		}
		if (temp == top)
		{
			top--;
			array[temp] = NULL;
		}
		return str;
	}
	bool validcheck(int a)
	{
		for (int i = 0; i < top; i++)
		{
			if (array[i] == a)
			{
				return false;
			}
		}
		return true;
		
	}
	void display()
	{
		temp = head;
		while (temp < top)
		{
			cout << array[temp];
			temp++;
		}

	}
	string allempty()
	{
		string str;
		temp = head;
		while (array[head] != NULL)
		{
			str += dequeue();
			
		}
		return str;
	}
};
class node
{
public:
	int data;
	bool visited;
	node* next;
	node()
	{
		visited = false;
		data = 0;
		next = NULL;
	}
	node(int a)
	{
		visited = false;
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
	string bfs = "\0";
	int arr[][2] = { {0,1},{0,2},{0,3},{1,2},{2,4} };
	handle* array = new handle[6];
	queue obj1;
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

		while (ptr != NULL)
		{
			if (obj1.validcheck(ptr->data))
			{
				obj1.Enqueue(ptr->data);
			}
			ptr = ptr->next;
		}
		array[i].head->visited = true;
		bfs += obj1.dequeue();
	}
	bfs += obj1.allempty();
	cout << bfs;
}
