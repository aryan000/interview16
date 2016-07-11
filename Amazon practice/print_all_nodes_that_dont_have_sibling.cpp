#include<bits/stdc++.h>
using namespace std;
typedef struct Node  Node;
struct Node
{
	int data;
	struct Node *left, *right;
};

Node *create(int data)
{
	Node*temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

Node * takeinput()
{
	int n;
	cout<<"root data ";
	cin>> n;
	if(n==-1)
		return NULL;
	Node*root = create(n);

	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node*first = q.front();
		q.pop();
		// cout<<"left data";
		cin>> n;
		if(n!=-1)
		{
			Node*left = create(n);
			first->left = left;
			q.push(left);
		}
		// cout<<"right data";
		cin>> n;
		if(n!=-1)
		{
			Node*right = create(n);
			first->right = right;
			q.push(right);
		}

	}

	return root;
}

void printSibling(struct Node* node)
{
	 if(node==NULL)
		return ;

	 
	if(node->left && !node->right)
		cout<< node->left->data << " ";
	if(node->right && !node->left)
		cout<< node->right->data << " ";
	 printSibling(node->left);
	 printSibling(node->right);
}

int main()
{
   Node *root = takeinput();

   printSibling(root);


}