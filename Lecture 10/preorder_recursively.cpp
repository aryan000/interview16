#include<iostream>
#include<climits>
using namespace std;
#include<queue> 
#include<stack>

typedef class BinaryTree btree;

class BinaryTree
{ public : 
 int data;
 BinaryTree *left;
 BinaryTree *right;

  BinaryTree( int data)
  { this->data = data;
  	 left = NULL;
  	 right  = NULL;

  }

  ~BinaryTree()
  {
  	if(left)
  		delete left;
  	if(right)
  		delete right;
  }
};


btree *takeinput()
{
	int n;
	cin>> n;
	if(n==-1)
		return NULL;

	btree *root = new btree(n);
	queue<btree*> q;
	q.push(root);
	while(!q.empty())
	{
		int temp;
		btree *first = q.front();
		q.pop();
		cin>> temp;

		if(temp!=-1)
		{
			btree *left = new btree(temp);
			first->left = left;
			q.push(left);
		}

		cin>> temp;
		if(temp!=-1)
		{
			btree *right = new btree(temp);
			first->right = right;
			q.push(right);
		}

		 
	}


	return root;
}

void preorder_recursive(btree *root)
{
	if(root==NULL)
		return;
	
	cout<< root->data << " ";
	preorder_recursive(root->left);
	preorder_recursive(root->right);
}


int main()
{	
	 
	btree *root = takeinput();
	 
 	preorder_recursive(root);

}