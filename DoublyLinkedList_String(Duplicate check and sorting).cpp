#include<iostream>
#include<string>
using namespace std;
class node
{
public:
	node* next;
	string data;
	node* prev;
public:
	node()
	{}
	node(string a)
	{
		data = a;
		next = NULL;
		prev = NULL;
	}
};
class handle
{
	node* temp;
	node* head;
	node* tail;
public:
	handle()
	{
		head = NULL;
		tail = NULL;
	}
	void insertnode(string a)
	{
		node* obj = new node(a);
		if (head == NULL)
		{
			head = obj;
			tail = head;
			return;
		}
		else if (tail->next != NULL)
		{
			obj->prev = tail;
			tail = tail->next;
		}
		tail->next = obj;
	}
	void display()
	{
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
};
string lowercase(string a)
{
	string b;
	for (int i = 0; i < a.length(); i++)
	{
		b += tolower(a[i]);
	}
	return b;
}
bool isempty(string a)
{
	if (a.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool compare(string a, string b)
{
	
	int x = 0;
	string c = lowercase(a);
	string d = lowercase(b);
	if (isempty(a) == true)
	{
		return false;
	}
	if (isempty(b) == true)
	{
		return false;
	}
	if (c[x] == d[x])
	{
		if (a > b)
		{
			return true;
		}
	}
	if (c[x] > d[x])
	{
		return true;
	}
	else
	{
		return false;
	}

}

void removedup(string * a,int z)
{

	int x = z - 1;
	for(int i = 0; i < z; i++)
	{
		for (int j = i + 1; j < z ; j++)
		{
			if (a[i] == a[j])
			{
				
				a[j] = "\0";
			}
		}
		
	}
	
}
int main()
{
	string a;
	string y;
	getline(cin, a);
	y = a;
	int x = a.length();
	int z = 1;
	int i = 0; 
	int j = 0;
	int w = x;
	while (x > 0)
	{
		if (a[i] == ' ')
		{
			int s = i + 1;
			char cc = y.at(s);
			if(cc != ' ')
			{
				z = z + 1;
			}
		
			
		}
		x--;
		i++;
	}
	string* arr = new string[z];
	i = 0;
	j = 0;
	while (w > 0)
	{
		if (a[i] == ' ')
		{
			int s = i + 1;
			char cc = y.at(s);
			if (cc != ' ')
			{
				j = j + 1;
			}
			else
			{
				goto here;
			}
		}
		else
		{
			arr[j] += a[i];
		}
		here:
		w--;
		i++;
	}
	removedup(arr, z);
	static int last = z - 1;
	for (int i = 0; i < z; i++)
	{
		for (int j = i + 1; j < z; j++)
		{
			
			 if (compare(arr[i], arr[j]) == true)
			{
				string a = arr[j];
				arr[j] = arr[i];
				arr[i] = a;
			}
		}
	}
	handle obj;
	i = 0;
	while (isempty(arr[i]) == false)
	{
		obj.insertnode(arr[i]);
		i++;
	}
	obj.display();
}
