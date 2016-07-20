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





int find(btree*root , btree *ans , int n)
{
	if(root==NULL)
		return INT_MIN;

	int diff = INT_MIN;
	if(n > root->data)
		diff =   root->data ;

	int ans1 = find(root->left,ans,n);
	int ans2 = find(root->right,ans,n);

	if(n==root->data && root!=ans)
		{  return root->data;}

	// return min(diff,min(ans1,ans2));
	return max(diff,max(ans1,ans2));	
}

btree* find_largest(btree*root)
{
	if(root==NULL)
		return root;

	btree* left = find_largest(root->left);
	btree* right = find_largest(root->right);

	btree * temp = NULL;
	if(left && right)
		{if(left->data > right ->data)
			temp = left;
		else temp = right;
	}

	else if(left)
		 temp = left;
	else if(right)
		temp = right;
	else if(!left && !right)
		return root;
	if(root->data > temp->data)
		return root;
	else return temp;
}

int main()
{	
	
	btree * root = takeinput();
	btree *ans = find_largest(root);

	// cout<< ans->data << endl;
	int temp= find(root,ans,ans->data);
	cout<< temp<< endl;
	

}