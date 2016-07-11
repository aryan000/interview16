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

 
void iterative_inorder(btree*root)
{
	if(root==NULL)
		return;
	stack<btree*> s;
	s.push(root);
	bool lastactionpushed = true;
	while(!s.empty())
	{
		btree*top = s.top();
		// s.pop();
		

		if(top->left && lastactionpushed)
			{
				s.push(top->left);
				continue;
			}
		else
		{ cout<< top->data << " ";
			s.pop();
			lastactionpushed = false;
		if(top->right)
			{
				s.push(top->right);
				lastactionpushed = true;
				 
			}
		}

	}
}

int main()
{	
	 
	btree *root = takeinput();
	 
 	iterative_inorder(root);

}