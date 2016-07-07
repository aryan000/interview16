#include<iostream>
using namespace std;
#include<queue>
#include<stack>
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


void print(btree *root , bool &ans)
{
	if(root==NULL)
		return ;

	
	if(root->right==NULL && root->left!=NULL)
		{ cout<< root->left->data << " "; ans = true; }

	if(root->left==NULL && root->right!=NULL)
		{ ans = true ; cout<< root->right->data << " "; }
	print(root->left,ans);
	print(root->right,ans);
	

		return;

}

int main()
{
	btree * root = takeinput();
		bool ans = false;
	print(root,ans);
	if(ans==false)
		cout<<"-1" << endl;

}