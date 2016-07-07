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





int find(btree*root , int n)
{
	if(root==NULL)
		return INT_MIN;

	int diff = INT_MIN;
	if(n>root->data)
		diff =   n-root->data ;

	int ans1 = find(root->left,n);
	int ans2 = find(root->right,n);

	return max(diff,max(ans1,ans2));
}

int find_largest(btree*root)
{
	if(root==NULL)
		return INT_MIN;

	int ans1 = find_largest(root->left);
	int ans2 = find_largest(root->right);

	return max(root->data,max(ans1,ans2));
}

int main()
{	
	
	btree * root = takeinput();
	int ans = find_largest(root);
	// cout<< ans << endl;
	int temp= find(root,ans);
	cout<< temp<< endl;
	

}