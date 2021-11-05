#include<iostream>
using namespace std;
class queue
{
private:
	int head = 0;
	int temp = 0;
	int array[5];
	int * front;
	int * end;
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
	void dequeue()
	{
		temp = head;
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
	for (int i = 0; i < 5; i++)
	{
		obj.Enqueue(i);
	}
	obj.dequeue();
	obj.dequeue();
	obj.display();
	
}
