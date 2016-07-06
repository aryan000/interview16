#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node(int data)
	{
	this-> data = data;
	next = NULL;
	}

	~Node()
	{
		if(next)
			delete next;
	}
};

Node * takeinput()
{
	int n;
	cin>> n;
	Node *head = NULL;
	Node *tail = NULL;
	while(n!=-1)
	{
		Node *temp   = new Node(n);
		if(head==NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		cin>> n;
	}

	return head;
}

void print(Node *head)
{
	while(head!=NULL)
	{
		cout<< head->data << " " ;
		head = head->next;
	}
	cout<< "-1" << endl;
}

void swap(Node*i , Node*j)
{
	 int temp = i->data;
	 i->data = j->data;
	 j->data = temp;



	return;
}

Node * sort( Node*head)
{

	Node *i = NULL;
	Node *j = NULL;
	Node *prev = NULL;
	Node *temp  = NULL;
	for(i=head;i->next!=NULL;i= i->next)
	{	
		  
		for(j=head;j->next!=NULL;j=j->next)
			{	
				if(j->data>j->next->data)
				{
					 swap(j,j->next);
				}

				 
			}
	}

	return head;
}

int main()
{
	Node *head = takeinput();
	head = sort(head);
	print(head);

}