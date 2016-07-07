#include<iostream>
using namespace std;
#include<queue>


class BinaryTree
{
	public : 
	int	 data;
	BinaryTree *left;
	BinaryTree *right;

	BinaryTree( int data )
	{	this->data = data;
		 left = NULL;
		 right = NULL;
	}

	~BinaryTree()
	{
		if(left) 
			delete left;
		if(right)
			delete right;
	}
};

