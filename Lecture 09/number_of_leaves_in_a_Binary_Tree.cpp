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

int count(btree *root)
{
	if(root==NULL)
		return 0;

	if(root->left==NULL && root->right==NULL)
		return 1;

	return count(root->left) + count(root->right);
}


int main()
{
	btree * root = takeinput();
	cout<< count(root) << endl;
}