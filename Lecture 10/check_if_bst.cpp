#include<iostream>
#include<climits>
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
  { this->data = data;
  	 left = NULL;
  	 right  = NULL;

  }

  ~BinaryTree()
  {
  	if(left)
  		delete left;
  	if(right)
  		delete right;
  }
};


btree *takeinput()
{
	int n;
	cin>> n;
	if(n==-1)
		return NULL;

	btree *root = new btree(n);
	queue<btree*> q;
	q.push(root);
	while(!q.empty())
	{
		int temp;
		btree *first = q.front();
		q.pop();
		cin>> temp;

		if(temp!=-1)
		{
			btree *left = new btree(temp);
			first->left = left;
			q.push(left);
		}

		cin>> temp;
		if(temp!=-1)
		{
			btree *right = new btree(temp);
			first->right = right;
			q.push(right);
		}
	}


	return root;
}

bool is_bst(btree *root ,int min =INT_MIN , int max = INT_MAX)
{
	 if(!root) // if root == NULL
	 	return true;
	 // cout << (root->data <min)  << " for " << root->data << " and " << min << endl;

	 if(root->data <min || root->data > max)
	 	{  
	 		return false;}

	 return is_bst(root->left,min,root->data) && is_bst(root->right,root->data , max);

}



int main()
{	
	
	btree *root = takeinput();

	 cout<< is_bst(root) << endl; 
}