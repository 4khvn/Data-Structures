#include<iostream>
using namespace std;
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
	void inqueue(int a)
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
	void Enqueue(int a)
	{
		queue * obj2 = new queue;
		
		if (array[head] != -1)
		{
			while (head < top)
			{
				int temp = dequeue();
				obj2->inqueue(temp);
			}
		}
		if (top < 9)
		{
			if (top == head)
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
		if (obj2->array[head] != -1)
		{
			while (obj2->head < obj2->top)
			{
				int temp = obj2->dequeue();
				inqueue(temp);
			}
		}
		delete[] obj2;
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
			array[temp] = -1;
			return a;
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
	obj.display();
}
