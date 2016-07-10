#include<iostream>
using namespace std;
#include<queue>
#include<climits>
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

btree * findlca(btree*root , int element1 , int element2)
{
	if(root==NULL)
		return NULL;

	if(root->data == element2 || root->data == element1)
		return root;

	btree *left = findlca(root->left,element1,element2);
	btree *right = findlca(root->right,element1,element2);

	if(left&&right)
		return root;

	if(left)
		return left;
	if(right)
		return right;

	else return NULL;
}


int main()
{	
	int a , b;
	cout<<"Enter first and second node data : ";
	 cin>> a >> b;
	btree * root = takeinput();
	 
	 
	btree *temp = findlca(root,a,b);

	cout<< temp->data << endl;
	

}