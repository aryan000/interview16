/* Generic tree */
// How to Implement tree 
// Take input from user and build generic tre

#include<iostream>
using namespace std;
#include<vector>

template<typename T>
class Treenode
{
	T data;
	vector<Treenode*> children;

	public : 
	 Treenode(T data)
	 {
	 	this->data = data;

	 }

	 T getdata()
	 {
	 	return data;
	 }

	 void setdata(T data)
	 {
	 	this->data = data;
	 }

	 void addchild(Treenode*child)
	 {
	 	children.push_back(child);
	 	return;
	 }

	 int numchildren()
	 {
	 	return children.size();
	 }
	 Treenode *getchild( int i )
	 {	
	 	if(i>children.size())
	 		throw "Out of Bound";

	 	return children.at(i);

	 }

	 void setchild(int i , Treenode *child)
	 {
	 	if(i>children.size())
	 		throw "Out of Bound";
	 	children[i] = child;

	 }


	 ~Treenode()
	 {
	 	for(int i =0;i<children.size();i++)
	 		 delete children.at(i);
	 }

};

