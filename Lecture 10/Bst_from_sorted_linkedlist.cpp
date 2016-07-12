#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}

	~Node()
	{
		if(next)
			delete next;
	}
};

class BST
{
	public : 
	int data;
	BST*left;
	BST *right;

	 BST(int data)
	 {
	 	this->data = data;
	 	left = NULL;
	 	right = NULL;
	 }

	 ~BST()
	 {
	 	if(left)
	 		delete left;
	 	if(right)
	 		delete right;

	 }
	
}; 

Node *getmiddleElement(Node *head )
{	
	if(head==NULL || head->next == NULL)
		return head;
	
	Node *curr = head;
	int count = 0;

	while(curr!=NULL)
	{
		count++;
		curr = curr->next;
	}

	curr = head;
	if(count%2==0)
	{
		count  = count/2 -1;
	}
	else
		count = count/2;

	int temp = 0;
	while(curr!=NULL && temp<count)
	{
		curr = curr->next;
		temp++;
	}

	return curr;

}


BST * create_bst(Node*head)
{
	if(head==NULL)
	 	return NULL;
	Node *left = head;
	Node *mid = getmiddleElement(head);
	cout<< mid->data << " and  " << endl;
	BST*root = NULL;
	if(mid->next)
		BST*root = new BST(mid->next->data);
	else return NULL;
	Node *right = mid->next->next;
	mid->next = NULL;
	root->left = create_bst(left);
	root->right = create_bst(right);

	return root;
}

void print(BST *root)
{
	if(root==NULL)
		return;
	queue<BST*> q;

	q.push(root);
	int current_level = 1;
	int next_level = 0;

	while(!q.empty())
	{
		BST *temp = q.front();
		q.pop();
		cout<< temp->data << " ";

		if(temp->left)
			{q.push(temp->left); next_level++;}
		if(temp->right)
			{q.push(temp->right); next_level++;}

		current_level--;
		if(current_level==0)
		{
			current_level = next_level;
			next_level = 0;
			cout<< endl;
		}
	}

	cout<< endl;
}

Node *takeinput( )
{	
	int temp = 0;
	Node *head = NULL;
	Node *tail = NULL;
	while(temp!=-1)
	{
		cin>> temp;
		if(temp==-1)
			break;
		Node *ptr = new Node(temp);

		if(head==NULL)
		{
			head = ptr ; 
			tail = ptr;
		}

		else 
		{
			tail->next = ptr;
			tail = ptr;
		}

	}

	return head;

}
int main()
{
	 
	Node *head = takeinput();
	BST *root = create_bst(head);
	print(root);
}