#include<iostream>
using namespace  std;
#include<vector>
#include<queue>

class Tree
{
	public : 
	int data;
	vector<Tree*> children;

	Tree( int data)
	{	this->data = data;
	}

	void add_child(Tree *child)
	{
		children.push_back(child);
	}

	void set_child(int i , Tree* child)
	{
		if(i>children.size())
		{
			// cout<< i << " th child does not exist";
			return;
		}

		children.at(i) = child;
		return;
	}

	Tree * getchild(int i)
	{
		if(i>children.size())
		{
			// cout<< i << " th child does not exist";
			return NULL;
		}

		return children.at(i);
	}

};

Tree * takelevelwiseinput()
{
	// cout<<"Enter the root data " ;
	int data;
	cin>> data;
	Tree* root = new Tree(data);
	queue<Tree*> q;
	q.push(root);
	int numofchildren;
	while(!q.empty())
	{
		Tree*temp = q.front();
		q.pop();
		// cout<<"Enter the number of children";
		cin>> numofchildren;
		int childdata;
		for(int i =0;i<numofchildren;i++)
		{
			// cout<< "child of " << temp->data << " : " << endl;
			cin>> childdata;
			Tree* child = new Tree(childdata);
			temp->add_child(child);
			q.push(child);
		}

	}
	

	 return root;
}


void print(Tree *root)
{
	if(root==NULL)
		return;
	queue<Tree*> q;
	q.push(root);
	int curr_level = 1;
	int next_level = 0;
	while(!q.empty())
	{
		Tree *temp = q.front();
		q.pop();
		 curr_level--;
		cout<< temp->data << " ";
		for(int i = 0;i<temp->children.size();i++)
		{
			Tree *child = temp->children.at(i);
			next_level++;
			q.push(child);
		}

		if(curr_level==0)
		 	{cout<< endl << endl;
		 		curr_level = next_level;
		 		next_level = 0;
		 	}



	}
}


int main()
{
	Tree *root = takelevelwiseinput();
	print(root);
}