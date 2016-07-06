#include<iostream>
using namespace std;
#include "linkedlist.h"

template <typename T>
class queue
{ 	
	int size ;
	public:
	Node<T> *arr ;
	Node <T>*tail;

	queue()
	{
	  arr = NULL;
	  tail = NULL;
	  size = 0;
	}

	~queue()
	{
	delete arr;
	}


	void enqueue(T data)
	{	

		Node<T> *temp = new Node<T> (data);
		size++;
		if(arr==NULL)
		{
			arr = temp ;
			tail = temp;
		}

		 tail->next = temp;
		 tail = temp;
		 return;
	}

	void dequeue()
	{	
		if(size==0)
		{
			cout<<"Queue is empty ... cannot Dequeue " ; return;
		}
		 	size--;
		   Node<T> *temp = arr;
		   arr = arr->next;
		   
		   temp->next = NULL;
		   delete temp;
	}

	T front()
	{
		if(size==0)
		{
			cout<<"Queue is empty  " ;  return 0;
		}	
		return  arr->data;
	}

	int getsize()
	{
		return size ;
	}

	bool isempty()
	{
		return size==0;
	}
};