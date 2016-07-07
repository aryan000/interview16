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

int height(btree*root)
{
	if(root==NULL)
		return 0;

	return 1 + max(height(root->left), height(root->right));
}

// O(n*h) solution for diameter of binary tree
int diameter(btree *root)
{	
	if(root==NULL)
		return 0;

	int left_height = height(root->left);
	int right_height = height(root->right);

	return max(left_height+right_height+1 , max(diameter(root->left) , diameter(root->right)));

}

// pair has first element as height and second element as diameter

pair<int,int> heightdiameter(btree *root)
{
	
	if(root==NULL)
		{pair<int,int> p(0,0);
			return p;
		}

	pair<int,int> left = heightdiameter(root->left);
	pair<int,int> right = heightdiameter(root->right);

	int height = 1+ max(left.first , right.first);
	int diameter = max(left.first+right.first+1,max(left.second,right.second));

	pair<int,int> p(height,diameter) ;
	return p;



}

int main()
{
	btree *root = takeinput();

	pair<int,int> p = heightdiameter(root);
	cout<< p.second << endl;
}