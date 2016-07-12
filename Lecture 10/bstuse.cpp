#include<iostream>
using namespace std;
#include<stdlib.h>
#include "BstClass.h"


int main()
{
	BST * root = NULL;
	int choice = 0;
	
	while(choice !=8)
	{ 
 		
		cout<<"\n1: Insert a data \n2: Find if exists \n3: Size of BST \n4: IsEmpty \n5: Remove a element \n6: Print inorder \n7: Print level order \n8: Exit\n";
		
	 cin>> choice;
	 system("cls");
	 if(choice==1)
	 {	int element;
	 	cout<< "Enter the element to be inserted  : " ;
	 	cin>> element;

	 	root = insert(root,element);
	 }
	 if(choice==2)
	 {	
	 	int element;
	 	cout<< "Enter the element to be searched  : " ;
	 	cin>> element;
	 	BST*temp = search(root,element);
	 	if(temp)
	 		cout<<"ELement exists " << endl;
	 	else
	 		cout<<"ELement does not exist " << endl;
	 }
	 if(choice==3)
	 {
	 	cout<< "size of bst is : " << root->size() << endl;
	 }
	 if(choice==4)
	 {
	 	if(root->isEmpty())
	 		cout<<"BST is  empty";
	 	else
	 		cout<<"BST is not empty";
	 }

	 if(choice ==5)
	 {
	 	int element;
	 	cout<< "Enter the element to be deleted : " ;
	 	cin>> element;

	 	 remove(root,element);
	 	/* to be done */

	 }

	 if(choice ==6)
	 {	
	 	cout<< "Inorder print is : " << endl;
	 	print(root);
	 }

	 if(choice==7)
	 {
	 	cout<<" level order wise print is : "<< endl;
	 	print_level_order(root);
	 }
	
	 
	}
}