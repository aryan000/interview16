#include<iostream>
using namespace std;
#include<vector>

class Tree
{
	public : 
	int data;
	vector<Tree*> children;

	Tree(int data)
	{
		this->data = data;
	}

	void add_child(Tree *child)
	{
		children.push_back(child);
	}

	Tree *getchild(int i )
	{
		if(i>children.size())
		{
			cout<<i << "th children does not exist";
			return NULL;
		}

		return children.at(i);
	}

	void setchild(int i , Tree*child)
	{	
		if(i>children.size())
			{
			cout<<i << "th children does not exist";
			
		}

		children.at(i) = child;
		return ;
	}
};

Tree* taketreeinput()
{
	int data;
	cout<<"Enter root data : " ;
	cin>> data;
	Tree *root = new Tree(data);
	int numofchildren;
	cout<<"Enter the number of children : ";
	cin>> numofchildren;

	for(int i =0;i<numofchildren;i++)
	{	
		root->add_child(taketreeinput());
	}

	return root;
}

void print(Tree *root)
{
	if(root==NULL)
		return ;

	cout<< root->data << " :";
	for(int i =0;i<root->children.size();i++)
	{
		cout<< root->children[i]->data << " ,";
	}
	cout<< endl;
	for(int i =0;i<root->children.size();i++)
		print(root->children[i]);

	return;
}


int main()
{
	Tree *root  = taketreeinput();
	print(root);
}