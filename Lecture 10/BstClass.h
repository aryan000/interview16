#include<iostream>
using namespace std;
#include<queue>

class BST
{
	public : 

	int data;
	static int totalsize ;
	BST *left;
	BST *right;

	BST(int data)
	{	totalsize++;
		this->data = data;
		left = NULL;
		right = NULL;

	}
	~BST()
	{	
		if(left)
			delete left;
		if(right)
			delete right;

	}

	 int size()
	{
		return totalsize;
	}

	bool  isEmpty()
	{
		return totalsize==0 ? true:false;
	}
	 
};

int BST:: totalsize = 0;
BST* insert(BST*root , int data)
{
	// Base Case , if the root is empty
	
	if(root==NULL)
	{	 
		BST*temp = new BST(data);	
		root = temp;
		return root;
	}

	if(data < root->data)
	{
		if(root->left)
		{
			BST *temp = insert(root->left,data);
			return root;
		}

		BST*temp = new BST(data);	
		root->left = temp;
		return root;

	}

	if(data > root->data)
	{
		if(root->right)
		{	
			BST *temp = insert(root->right,data);
			return root;

		}
		BST*temp = new BST(data);	
		root->right = temp;
		return root;
	}


	if(data==root->data)
	{
		cout<<"Cannot add duplicate elements in BST " << endl;
		return root;
	}
}

BST* search(BST*root , int data)
{
	// Base case
	if(root==NULL)
		return root;

	if(root->data==data)
		return root;

	if(root->data>data)
		return search(root->left,data);
	else
		return search(root->right,data);
}

BST* inorder_successor(BST*root )
{
	 BST * current = root;
	 while(current->left!=NULL)
	 	current = current->left;

	 return current;

}

BST* remove (BST*root , int data)
{
	if(root==NULL)
	{
		cout<< "BST is empty";
		
	}

	// data lies in left subtree
	if(data<root->data)
		root->left = remove(root->left,data);

	// data lies in right subtree
	else if(data > root->data)
		root->right = remove(root->right,data);

	// data is the root data 
	else 
	{ 	
		// if node is leaf  or one single child
		if(root->left==NULL)
		{
			BST*temp = root->right;
			delete root;
			return temp;
		}
		if(root->right==NULL)
		{
			BST*temp = root->left;
			delete root;
			return temp;
		}

		// node has 2 children 

		BST* successor = inorder_successor(root->right);
		root->data = successor->data;
		root->right = remove(successor,root->data);

		return root;

	}




}



void print(BST *root)
{
	if(root==NULL)
		return ;

	if(root->left)
		print(root->left);
	cout<< root->data << " ";
	print(root->right);
}

void print_level_order(BST*root)
{
	if(root==NULL)
		return;
	cout<< endl;
	queue<BST*> q;
	q.push(root);
	int current_level = 1;
	int next_level = 0;

	while(!q.empty())
	{
		BST*temp = q.front();
		q.pop();

		if(temp->left)
		{
			q.push(temp->left);
			next_level++;
		}

		if(temp->right)
		{
			q.push(temp->right);
			next_level++;

		}
		cout<< temp->data << " ";
		current_level--;
		if(current_level==0)
		{
		current_level=	next_level;
		next_level=0;
		cout<< endl;

		}
	}
}