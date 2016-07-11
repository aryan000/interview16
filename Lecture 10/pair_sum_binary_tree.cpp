#include<iostream>
#include<climits>
using namespace std;
#include<queue> 
#include<stack>

typedef class BinaryTree btree;

class BinaryTree
{ public : 
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

 
bool check_sum(btree *root ,btree*self, int k )
{
	if(root==NULL)
		return false;
	if(root->data==k && root!=self)
		{ //cout<< root->data << " " << endl; 
		return true;
		}
	return check_sum(root->left,self,k) || check_sum(root->right,self,k);
}

// This is O(n^2) solution and O(1) space solution
// Another solution will be to store it in array and sort and then search for pair
// T(n) = O(nlogn) + O(n)
// S(n) = O(n) for storing inorder or preorder or postorder
bool has_sum(btree*root,btree*head,int k)
{
	if(root==NULL)
		return 0;

	if(check_sum(head,root,k-root->data))
		 return true;

	return has_sum(root->left,head,k) || has_sum(root->right,head,k);
}
 
int main()
{	
	 	int k;
	 	cin>> k;
	btree *root = takeinput();
	 
 	cout<< has_sum(root,root,k) << endl;

}