#include<iostream>
using namespace std;
#include "BinaryTree.h"


BinaryTree * takeinput()
{
	int rootdata;
	cout<<"Enter rootdata";
	cin>> rootdata;
	BinaryTree *root = new BinaryTree(rootdata);
	queue<BinaryTree*> q;
	q.push(root); int input;
	while(!q.empty())
	{
		BinaryTree *temp = q.front();
		q.pop();

		cin>> input;
		if(input!=-1)
		{
			BinaryTree *left = new BinaryTree(input);
			temp->left = left;
			q.push(left);
		}

		cin>> input;
		if(input!=-1)
		{
			BinaryTree *right = new BinaryTree(input);
			temp->right = right;
			q.push(right);
		}

	}

	return root;
}


void print( BinaryTree *root)
{
	queue<BinaryTree*> q;
	if(root==NULL) 
		return;
	q.push(root);	

	int current_level = 1;
	int next_level = 0;
	while(!q.empty())
	{	
		BinaryTree *temp = q.front();
		q.pop();
		cout<< temp->data << " ";

		if(temp->left!=NULL)
		{
			next_level++;
			q.push(temp->left);
		}
		if(temp->right!=NULL)
		{
			next_level++;
			q.push(temp->right);
		}

		current_level--;
		if(current_level==0)
		{
			current_level = next_level;
			next_level = 0;
			cout<< endl;
		}

	}
}


int main()
{
	BinaryTree * root = takeinput();
	print(root);

}