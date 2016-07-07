#include<iostream>
using namespace std;
#include<queue>
typedef class BinaryTree btree;

class Node
{
	public : 
	int data;
	Node*next;

	Node( int data)
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



vector<Node*> get(btree *root)
{	
	vector<Node*> ans;
	if(root==NULL)
		{ Node *ptr = new Node(-1);
			ans.push_back(ptr);
			return ans;
			
		}

	queue<btree*> q;
	q.push(root);
	int curr_level = 1;
	int next_level = 0;
	
	Node *head = NULL;
	Node *tail = NULL;
	while(!q.empty())
	{
		btree *temp = q.front();
		q.pop();
		Node* ptr = new Node(temp->data);

		// cout<< temp->data << " ";
		if(temp->left!=NULL)
			{q.push(temp->left);
				 next_level++;
				}

		if(temp->right!=NULL)
			{q.push(temp->right);
				next_level++;
			}

	  curr_level --;

	  if(head==NULL)
	  {
	  	  head = ptr;
	  	  tail = ptr;

	  }
	  else
	  {
	  	tail->next = ptr;
	  	tail = ptr;

	  }

	  if(curr_level==0)
	  {	//cout<< "level change at " << temp->data << endl;
	  	curr_level = next_level;
	  	next_level = 0;
	  	ans.push_back(head);
	  	head  = NULL;
	  	tail = NULL;
	  	// cout<<endl;

	  }
	}

	return ans;
}

int main()
{
	btree * root = takeinput();
	vector<Node*> ans = get(root);

	for(int i = 0;i<ans.size();i++)
	{
		Node*temp = ans[i];
		while(temp!=NULL)
		{
			cout<< temp->data << " ";
			temp = temp->next;
		}
		cout<< endl;
	}

}