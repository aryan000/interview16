#include<iostream>
using namespace std;
#include<queue>
#include<cmath>
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

int depth(btree *root)
{
	if(root==NULL)
		return 0;

	return 1 + max(depth(root->left) , depth(root->right));

}
// This is O(n*h) solution where n is number of nodes in tree and h is the height
bool isbalanced1(btree *root)
{	
	if(root==NULL)
		return true;

	if(root->left==NULL && root->right==NULL) 
			return true;

	if(abs(depth(root->left)-depth(root->right))>1)
		return false;

	return isbalanced1(root->left) && isbalanced1(root->right);

	
}

pair<bool,int> isbalanced(btree *root)
{
	if(root==NULL)
	{
		pair<bool,int> p(true,0);
		return p;
	} 

	pair<bool,int> left = isbalanced(root->left);
	pair<bool,int> right = isbalanced(root->right);

	if(!(left.first&& right.first))
		{
			pair<bool,int> p(false,1+max(left.second,right.second));
			return p;
		}

	bool ans = abs(left.second-right.second)>1?false:true;
	pair<bool,int> p(ans,1+max(left.second,right.second));

	return p;


}

int main()
{
	btree * root = takeinput();
	pair<bool,int> p = isbalanced(root);
	 // cout<< isbalanced(root) << endl; 
	cout<< p.first << endl;
}