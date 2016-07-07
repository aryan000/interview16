#include "linkedlist.h"
#include<iostream>
using namespace std;

template <typename T>
class dequeue
{	
	int size ;
	public :

	  Node<T> *arr;
	  Node<T>*head;
	  Node<T>*tail;

	  dequeue()
	  {
	  	arr = NULL;
	  	head = NULL;
	  	tail = NULL;
	  	size = 0;
	  }

	  ~dequeue()
	  {
	  	delete arr;
	  }

	  void push(T data )
	  {
	  	Node<T>*temp =  new Node<T>(data); 

	  	if(head==NULL)
	  	{
 			head  = temp;
 			tail = temp;
 			return;
	  	}

	  	temp->next = head;
	  	head = temp;

	  	return;

	  }

	  T pop()
	  {

	  	if(head==NULL)
	  	{
	  		cout<<"dequeue is empty:"; return 0;
	  	}

	  	if(head==tail)
	  	{	
	  		T temp = head->data;
	  		head = tail = NULL;
	  		return temp;
	  	}

	  	Node<T>*temp = head;
	  	head = head->next;
	  	T data = temp->data;
	  	temp->next = NULL;
	  	delete temp;
	  	return data;
	  }

	  void inject( T data)
	  {
	  	Node<T> *temp = new Node<T>(data);


	  	if(tail ==NULL)
	  	{
	  		head  =  temp;
	  		tail = temp;
	  		return ;
	  	}

	  	tail->next = temp;
	  	tail = temp;

	  	return ;
	  }

	  T eject()
	  {
	  	if(tail==NULL)
	  	{
	  		cout<<"dequeue is empty !!!" << endl; 
	  		return 0; // generally exception should be thrown
	  	}

	  	if(head==tail)
	  	{
	  		T data = head->data;
	  		
	  		Node<T>*temp = head;
	  		head = NULL;
	  		tail  = NULL;
	  		delete temp;
	  		return data;
	  	}

	  	Node<T> *temp = head;
	  	while(temp->next!=tail)
	  		temp = temp->next;

	  	T data = tail->data;
	  	delete tail;
	  	tail = temp;
	  	return data;

	  }


	  void print()
	  {
	  	Node<T>*temp = head;

	  	while(temp!=NULL)
	  	{
	  		cout<< temp->data << " ";
	  		temp = temp->next;
	  	}
	  	cout<< "-1" << endl;
	  }

};