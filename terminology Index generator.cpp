/* 
Question: Suppose you are given a text with multiple lines and each line is represented by a line number. Your task is to read the text line by line and generate an index of terminologies. An index of terminologies is a list providing information about the line number(s) on which a term occurs. You are also given a list of terminologies for which you have to generate the index. To perform this task, you have to read the text and insert each terminology into a binary search tree. To record line numbers for a term, use a linked list for each term which should be associated with the node representing the term. Finally, using the constructed binary search tree, output the terminology index in alphabetical order of the terminologies. 

The input will contain the following:

First-line will contain the number of terminologies (N). The next N lines will contain the N terminologies (i.e., one terminology per line).

After reading all the terminologies you will read an integer (M) indicating how many lines you have to read further for the text. Each line contains the line number in the beginning followed by the text.

The output will be as follow:

Each line will contain terminology and line numbers separated by space. */
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string temp;
string line;
int count2;
class node
{
public:
	string data;
	node* next;
	node* right;
	node* left;
	node()
	{
	    next =NULL;
		right = NULL;
		left = NULL;
	}
	node(string a)
	{
	    next = NULL;
		right = NULL;
		left = NULL;
		data = a;
	}
};
class handle
{
public:

	node* root;

public:
	handle()
	{
		root = NULL;

	}

	node* insert(node* a, string b)
	{
		if (a == NULL)
		{
			node* obj = new node(b);
			a = obj;
			return obj;
		}
		else if (a->data > b)
		{
			a->left = insert(a->left, b);
		}
		else if (a->data < b)
		{
			a->right = insert(a->right, b);
		}
		return a;

	}

	node* display(node* a)
	{
		if (a->left != NULL)
		{
			display(a->left);
		}
		node* temp = a;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
		if (a->right != NULL)
		{
			display(a->right);
		}
		return a;
	}
	node* Inorder(node* a, string c, string b)
	{
		if (a->left != NULL)
		{
			Inorder(a->left, c, b);
		}
		if (a->data == c)
		{
			while (a->next != NULL)
			{
				a = a->next;
			}
			node* obj = new node(b);
			a->next = obj;
		}
		if (a->right != NULL)
		{
			Inorder(a->right, c, b);
		}
		return a;
	}
	node* findword(node* a, string b, int c)
	{
		if (a->left != NULL)
		{
			findword(a->left, b, c);
		}
		line = "";
		int x = 0;
		string tempo = a->data;
		for (int i = 0; i < c; i++)
		{
			if (b[i] == tempo[0])
			{
				for (int j = i; j <= j + (tempo.size()); j++)
				{
					if (x <= tempo.size())
					{
						if (b[j] == tempo[x])
						{
							temp += b[j];

						}
						else
						{
							break;
						}
					}
					x++;
					if (x > tempo.size())
					{
						break;
					}
				}
				x = 0;
				int i = 0, chk = 0;
				while (tempo[i] != '\0' || temp[i] != '\0')
				{
					if (temp[i] != tempo[i])
					{
						chk = 1;
						break;
					}
					i++;
				}
				if (chk == 0)
				{
					for (int i = 0; i < c; i++)
					{
						if (b[i] != ' ')
						{
							line += b[i];
						}
						else
						{
							break;
						}

					}
					Inorder(root, temp, line);
				}
				else
				{

					temp = "";
				}
			}

		}
		if (a->right != NULL)
		{
			findword(a->right, b, c);
		}
		return a;

	}

	
};

int main()
{
	handle obj;
	cin >> count2;
	getchar();
	for (int i = 0; i < count2; i++)
	{
		string a;
		getline(cin, a);
		obj.root = obj.insert(obj.root, a);
	}
	for (int i = 0; i < 7; i++)
	{
		string b;
		getline(cin, b);
		b += " ";
		int x = b.size();
		obj.findword(obj.root, b, x);
	}
obj.display(obj.root);
}
