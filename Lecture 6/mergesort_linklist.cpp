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

Node * getmid(Node *head)
{	
	if(head==NULL || head->next==NULL)
		return head;

	Node*slow = head;
	Node *fast = head->next;

	while(fast!=NULL)
	{
		fast = fast->next;
		if(fast!=NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	return slow;
} 

Node* merge(Node *first , Node*second)
{ 

	if(first==NULL)
		return second;
	if(second==NULL)
		return first;

	Node* head = NULL;

	
	if(first->data<=second->data)
	{
		head = first;
		head->next = merge(first->next,second);
	}
	else
	{
		head = second;
		head->next = merge(first,second->next);
	}
	return head;
}



void mergesort(Node ** head)
{	
	if(*head==NULL || (*head)->next==NULL)
		return ;

	Node *mid = getmid(*head);
	if(mid==NULL) return;
	Node *first = *head;
  
	Node* second = mid->next;
	mid->next = NULL;

	mergesort(&first);
	mergesort(&second);

	*head = merge(first,second);

}

int main()
{
	Node*head = takeinput();
	mergesort(&head);

	print(head);
}