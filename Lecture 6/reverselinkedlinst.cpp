#include<iostream>
using namespace std;

template <typename T>
class Node
{
	public : 
	T data;
	Node *next;

	Node( T data)
	{	this->data = data;
		 next = NULL;
	}

	~Node()
	{
		if(next)
			delete next;
	}

	
};

Node<int>* take_linked_list_input()
{
	Node<int> * head = NULL;
	Node<int> * tail = NULL;
	int n ;
	cin>> n;
	while(n!=-1)
	{
		Node <int>* tempnode = new Node<int> (n);
		tempnode->next = NULL;
		if(head==NULL)
		{
			head = tempnode;
			tail = tempnode;
			head->next=NULL;
		}

		else
		{
			tail->next= tempnode;
			tail = tempnode;
		}
     
     cin>> n;

	}

	return head;
}

void print( Node<int>* head)
{
	
	while(head!=NULL)
	{
		cout<< head->data << " ";
		head = head->next;
	}
	cout << -1 << endl;
}

Node<int>* iterative_reverse(Node<int> *head)
{
	if(head==NULL || head->next==NULL)
		return head;

	Node<int> * prev = NULL;
	Node<int>* curr = head;
	Node<int>*next = NULL;

	while(curr!=NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	head = prev;

	return head;


}


int main()
{
	Node<int> *head = take_linked_list_input();
	head = iterative_reverse(head);
	print(head);

	delete head;

}