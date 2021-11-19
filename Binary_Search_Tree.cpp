#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* right;
	node* left;
	node()
	{
		right = NULL;
		left = NULL;
	}
	node(int a)
	{
		data = a;
	}
};
class handle
{
public:
	node* root;
	node* tail;
public:
	handle()
	{
		root = NULL;
	}
	node* insert(node * a,int b)
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
	node* preorder(node * a)
	{
		cout << a->data << " " ;
		if (a->left != NULL)
		{
			preorder(a->left);
		}
		if (a->right != NULL)
		{
			preorder(a->right);
		}
		return 0;
	}
	node* postorder(node* a)
	{
		
		if (a->left != NULL)
		{
			postorder(a->left);
		}
		if (a->right != NULL)
		{
			postorder(a->right);
		}
		cout << a->data << " " ;
		return 0;
	}
	node* Inorder(node* a)
	{
		if (a->left != NULL)
		{
			Inorder(a->left);
		}
		cout << a->data << " " ;
		if (a->right != NULL)
		{
			Inorder(a->right);
		}
		return a;
	}
	node* search(node* a, int b)
	{
		if (a->data == b)
		{
			cout << "Found";
			return a;
		}
		else
		{
			if (a->left != NULL && a->data > b)
			{
				return search(a->left, b);
				
			}
			else if (a->right != NULL && a->data  < b)
			{
				return search(a->right, b);
			}
			
		}
		return a;
	}
	node* Min(node* a)
	{
		while (a->left != NULL)
		{
			a = a->left;
		}
		return a;
	}
	node* max(node* a)
	{
		while (a->right != NULL)
		{
			a = a->right;
		}
		return a;
	}
	node* deleteN(node* a, int b)
	{
		if (a == NULL)
		{
			return a;
		}
		else if (a->data > b)
		{
			a->left = deleteN(a->left, b);
		}
		else if (a->data < b)
		{
			a->right = deleteN(a->right, b);
		}
		else
		{
			if (a->left == NULL && a->right == NULL)
			{
				delete a;
				a = NULL;
				return NULL;
			}
			else if (a->right == NULL)
			{
				node* temp = a;
				a = a->left;
				delete temp;
				return a;
			}
			else if (a->left == NULL)
			{
				node* temp = a;
				a = a->right;
				delete temp;
				return a;
			}
			else
			{
				node* temp = Min(a->right);
				a->data = temp->data;
				a->right = deleteN(a->right, temp->data);
				return a;
			}

		}
		return a;
	}
};
int main()
{
	handle obj;
	obj.root = obj.insert(obj.root, 1);
	obj.root = obj.insert(obj.root, 4);
	obj.root = obj.insert(obj.root, 0);
	obj.root = obj.insert(obj.root, 2);
	obj.root = obj.insert(obj.root, 7);
	 obj.Inorder(obj.root);
	 cout << endl;
	 obj.preorder(obj.root);
	 cout << endl;
	 obj.postorder(obj.root);
	 cout << endl;
	 obj.search(obj.root,4);
	  obj.deleteN(obj.root, 4);
	  cout << endl;
	 obj.Inorder(obj.root);
}