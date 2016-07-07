#include<iostream>
using namespace std;
#include "GenericTree.h"


Treenode<int> * taketreeinput()
{
	int rootdata;
	cout<<" Enter root data : " ;
	cin>> rootdata;
	Treenode<int>* root = new Treenode<int> (rootdata);
	int numofchildren;
	cout << "Enter number of children " << endl;
	cin>> numofchildren;

	for(int i =0;i<numofchildren;i++)
	{
		root->addchild(taketreeinput());
	}

	return root;
}

void print( Treenode<int> *root)
{
	cout<< root->getdata() << ":";

	for(int i =0;i<root->numchildren();i++)
	{
		 cout<< root->getchild(i)->getdata() << " ,";
	}

	cout<< endl;
		for(int i =0;i<root->numchildren();i++)
			 print(root->getchild(i));
}
int main()
{
	Treenode<int>* root = taketreeinput();

	try
	{
		print(root);
	}
	catch (const char* message)
	{
		cout<< message << endl;
	}
}