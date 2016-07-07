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


int getsum(Tree *root)
{
	int sum = root->data;
	for(int i = 0;i<root->children.size();i++)
	{
		sum += root->children.at(i)->data;
	}

	return sum;
}

Tree *findmax(Tree*root)
{
	Tree *ans = root;
	int ansmax = getsum(root);

	Tree *temp = NULL;  

		for(int i = 0;i<root->children.size();i++)
		{
			temp = findmax(root->children.at(i));
				if(ansmax<getsum(temp))
					{	ansmax = getsum(temp);
						ans = temp;
					}
		}

		return ans;

}

int main()
{
	Tree *root = takelevelwiseinput();
	Tree *temp = findmax(root);

	cout<< " The node with largest sum has sum : " << getsum(temp) << endl;
}