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


btree *takeinput(int count)
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

		count--;
		if(count<0) break;
	}


	return root;
}

bool is_identical(btree*root1 , btree*root2){

	if(root1==NULL && root2==NULL)
		return true;
	if(root1==NULL || root2==NULL)
		return false;

	if(root1->data !=root2->data)
		return false;

	return is_identical(root1->left,root2->left)&& is_identical(root1->right,root2->right);


}



int main()
{	
	int n , k;
	cin>> n ; 
	cin>> k;
	
	btree *root1 = takeinput(n);
	btree *root2 = takeinput(k);

	 cout<< is_identical(root1,root2) << endl; 
}