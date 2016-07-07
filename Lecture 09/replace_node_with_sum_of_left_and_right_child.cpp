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

void replace( btree *&root)
{
	if(root==NULL)
		return;

  	int sum = 0;
  	if(root->left!=NULL)
  		sum += root->left->data;
  	if(root->right!=NULL)
  		sum+= root->right->data;

  	replace(root->left);
  	replace(root->right);

  	root->data = sum ;




}

void print(btree *root)
{
	if(root==NULL)
		{cout<<"-1" ; 
				return;
		}

	queue<btree*> q;
	q.push(root);
	int curr_level = 1;
	int next_level = 0;
	while(!q.empty())
	{
		btree *temp = q.front();
		q.pop();

		cout<< temp->data << " ";
		if(temp->left!=NULL)
			{q.push(temp->left);
				 next_level++;
				}

		if(temp->right!=NULL)
			{q.push(temp->right);
				next_level++;
			}

	  curr_level --;
	  if(curr_level==0)
	  {
	  	curr_level = next_level;
	  	next_level = 0;
	  	cout<<endl;

	  }
	}

	return;
}

int main()
{
	btree * root = takeinput();
	replace(root);
	print(root);

}