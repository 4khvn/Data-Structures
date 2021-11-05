#include<iostream>
using namespace std;
class queue
{
private:
	int array[5];
	int top =0;
	 int last =-1;
	 int total =0;
	int max;
public:
	queue()
	{}
	queue(int a)
	{
		
		max = a;
	}
	bool overflow()
	{
		if (last >= max)
		{
			return false;

		}
		else
		{
			return true;
		}
	}
	void enqueue(int a)
	{
		if (!overflow())
		{
			if (top > 0 && last == max )
			{
				last = 0;
				array[last] = a;
				

			}
			else if (top > 0  &&  last > 0 && last < max )
			{
				
				array[last] = a;
				
			}
			else{
				cout << "Array Full";
			}
			
		}
		else
		{
			last++;
			
			
			
			array[last] = a;
			total ++;
		
	
			}
	}
	void dequeue()
	{
		array[top] = NULL;
		top++;
		
	}
	void display()
	{
		if (!overflow())
		{
				for (int i = top ; i <= max; i++)
			{
				cout << array[i];
			}
			for (int i = last; i < top; i++)
			{
				cout << array[i];
			}
			
		}
		else
		{
		for (int i = 0; i < 5; i++)
			{
				cout << array[i];
			}
		}
	}
};
int main()
{
	queue obj(4);
	for (int i = 0; i < 5; i++)
	{
		obj.enqueue(i);
	}
	obj.dequeue();
	obj.enqueue(4);
	//obj.dequeue();
	//obj.enqueue(6);
	//obj.dequeue();
	obj.enqueue(9);
	obj.display();
}
