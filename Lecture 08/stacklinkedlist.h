#include<iostream>
using namespace std;
#include "linkedlist.h"

template <typename T>
class stack
{	
	int size;
	public : 
	
	Node<T>* arr;

	stack()
	{
		arr = NULL;
		size = 0;
	}

	~stack()
	{
		delete arr;
	}


	void push(T data)
	{
		Node<T>*temp = new Node<T>(data);
		size ++;
		cout<<"pushing";
		if(arr==NULL)
		{
			arr = temp;
			return;
		}

		temp->next = arr;
		arr = temp;
		
		return;

	}

	void pop()
	{
		if(size==0)
			cout<<" stack is empty.. cannot pop elements "<< endl;

	   else
	   {
	   	 Node<T> *temp = arr;
	   	 arr = arr->next;
	   	 temp->next = NULL;
	   	 delete temp;
	   	 size --;
	   }
	   return;
	}

	T top()
	{
		if(size==0)
			{cout<< " stack is empty ... "; return 0;}

		return arr->data ;
	}

	int getsize()
	{
		return size;
	}

	bool isempty()
	{
		return size==0;
	}


};


