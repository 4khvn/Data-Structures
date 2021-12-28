#include<iostream>
using namespace std;
int arr[5] = { -1 };
int cont = 0;
class queue
{
private:
	int head = 0;
	int temp = 0;
	int array[5] = { -1 };
	int* front;
	int* end;
	int top = 0;
public:
	queue()
	{
		front = NULL;
		end = NULL;
	}
	void Enqueue1(int a)
	{
		if (top < 9)
		{
			if (head == top)
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
	void Enqueue(int a)
	{
		if (top < 9)
		{
			if (head == top)
			{
				array[head] = a;
				front = &array[head];
				end = front;
				top++;
			}
			else
			{
				sort(a);
			}
		}
		else
		{
			cout << "Array full.";
		}
	}
	int peek()
	{
		int a = array[head];
		return a;
	}
	void sort(int a)
	{

		while (head != top)
		{
			int temp = peek();
			if (a < temp)
			{
				arr[cont] = a;
				cont++;
				while (head != top)
				{
					int temp = dequeue();
					arr[cont] = temp;
					cont++;
				}
				for (int i = 0; i < cont; i++)
				{
					Enqueue1(arr[i]);
					arr[i] = -1;
				}
				cont = 0;
				return;
			}
			int b = dequeue();
			arr[cont] = b;
			cont++;
		}
		for (int i = 0; i < cont; i++)
		{
			Enqueue1(arr[i]);
			arr[i] = -1;
		}
		
		Enqueue1(a);
		cont = 0;
	}
	int dequeue()
	{
		temp = head;
		int a = array[temp];
		while (temp != top)
		{
			array[temp] = array[temp + 1];
			temp++;
		}
		if (temp == top)
		{
			top--;
		
			array[temp] = NULL;
			return a;
		}

	}
	int is_empty()
	{
		if (head == top)
			return 1;
		else
			return 0;
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
};
int main()
{
queue obj;
obj.Enqueue(4);
obj.Enqueue(7);
obj.Enqueue(8);
obj.Enqueue(16);
obj.Enqueue(15);
obj.Enqueue(2);
obj.display();
}
