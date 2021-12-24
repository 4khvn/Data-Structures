/*You are given a positive natural number n, which represents number of nodes in a Binary Search Tree (BST). The next input line give you space separated n integers values that you need to insert into an initally empty BST. The resultant tree thus produced will be used to perform output. You need to find min and max values for each level, strating from level 1 (root) where there is only one value so you can make it both min and max from the next level you produce min and max from that level. Consider the BST given below as an example: 
At level 1 , there is only one value 34, hence the pair of min and max will be 34 34 

At level 2, there are two values 29 and 65, so the pair will be 29 65

At level 3, there are four values 21, 31, 43, 87 and the min and max will be 21 87 

At level 4, the final level for the above tree , we have 28, 30 and 56 so the pair will be 28 56. */
#include<iostream>
using namespace std;
int maxxx;
int miin;
int depth;
class node
{
public:
	int data;
	node* right;
	node* left;
	node()
	{
	    data =0;
		right = NULL;
		left = NULL;
	}
	node(int a)
	{
		data = a;
		right = NULL;
		left = NULL;
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
	node* insert(node* a, int b)
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
	void Inorder(node* a)
	{
		if (a->left != NULL)
		{
			depth = depth + 1;
			Inorder(a->left);
		}
		
		if (a->right != NULL)
		{
			depth = depth + 1;
			Inorder(a->right);
		}
		return ;
	}
	void findminmax(int a)
	{
		if (miin == NULL && maxxx == NULL)
		{
			miin = maxxx = a;
		}
		if (a >= maxxx)
		{
			maxxx = a;
		}
		if (a <= miin)
		{
			miin = a;
		}
	}
	bool dataheight(node* a, int hei)
	{
	
		if (a == NULL) 
		{
			
			return false;
		}
		if (hei == 0)
		{
			
			findminmax(a->data);
			return true;
		}
		bool qq = dataheight(a->left, hei-1 );
		bool rr = dataheight(a->right, hei-1);
		return qq || rr;
	}
	void heightwise(node* a)
	{
		int hei = 0;
		maxxx, miin = 0;
		while (dataheight(a, hei)) {
			hei++;
			cout << miin << " " << maxxx << endl;
			miin = NULL;
			maxxx = NULL;
		}
	}
};
int main()
{
	int count;
	cin >> count;
	handle obj;
	for (int i = 0; i < count; i++)
	{
		int a;
		cin >> a;
		obj.root = obj.insert(obj.root,a);
	}
	obj.heightwise(obj.root);
}
