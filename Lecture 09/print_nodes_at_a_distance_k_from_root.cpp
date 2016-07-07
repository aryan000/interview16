#include<iostream>
using namespace std;
#include<queue>
typedef class BinaryTree btree;

class BinaryTree
{
	public : 
	int data;
	BinaryTree *left;
	BinaryTree *right;

	BinaryTree( int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTree()
	{
		if(left) delete left;
		if(right) delete right;
	}
};


btree * takeinput()
{
	int rootdata;
	cin>> rootdata;
	if(rootdata==-1)
		return NULL;
	btree *root = new btree(rootdata);
	queue<btree*> q;
	q.push(root);
	int input;
	while(!q.empty())
	{	
		btree *temp = q.front();
		q.pop();

		cin>> input;
		if(input!=-1)
		{
			btree *left = new btree(input);
			temp->left = left;
			q.push(left);
		}
		cin>> input;
		if(input!=-1)
		{
			btree *right = new btree(input);
			temp->right = right;
			q.push(right);
		}


	}


	return root;
}

void print(btree *root , int k )

{	
	if(root==NULL)return;
	if(k==0)
	{
		cout<< root->data << " ";
		return;
	}

	print(root->left,k-1);

	print(root->right,k-1);
	return;
}

int main()
{	
	int k ;
	cin>> k;
	btree *root = takeinput();
	print(root,k);
}