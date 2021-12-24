#include<iostream>
using namespace std;
static int arrindex = 0;
class node
{
public:
	int data;
	node* next;
	node * prev;
	node()
	{
		data = 0;
		prev = NULL;
		next = NULL;
	}
	node(int a)
	{
		next = NULL;
		prev = NULL;
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
			obj->prev = tail;
			tail = tail->next;
		}
		tail->next = obj;
	}

};
int main()
{
	int arr[][2] = { {0,1},{0,2},{1,0},{1,3},{2,0},{2,3},{3,1},{3,5},{4,2},{4,5},{5,3},{5,4} };
	handle* array = new handle[6];
	
	for (int i = 0; i <= 11; i++)
	{
		bool check = false;
		for (int k = 0; k < 6; k++)
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
			for (int j = 0; j <=11; j++)
			{
				if (arr[j][0] == obj.head->data)
				{
					int x = arr[j][1];
					obj.insert(x);
				}
			}
		}
	}

	for (int i = 0; i < 6; i++)
	{
		auto ptr = array[i].head;
		while (ptr != NULL)
		{
			cout << ptr->data << " --";
			ptr = ptr->next;
		}
		cout << endl;
	}

}
