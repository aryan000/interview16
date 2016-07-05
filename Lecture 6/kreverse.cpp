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

Node * reverse(Node *head , int k)
{
	if(head==NULL)
		return head;
	Node * curr = head;
	Node *prev = NULL;
	Node *next = NULL;
	int count = 0;
	while(curr!=NULL && count<k)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}

	if(next!=NULL)
		head->next = reverse(next,k);

	return prev;
}

// Node * kreverse(Node * head , int k )
// {
// 	if(head==NULL || head->next==NULL)
// 		return head;
// 	int count = 0;
// 	Node * temp = NULL;
// 	Node *start = head; 
// 	Node *tail = NULL;
// 	Node *next = NULL;
// 	while(head!=NULL  )
// 	{	
// 		count++;
		 		 
// 		if(count%k==0)
// 		{
// 			next= head->next;
// 			head->next = NULL;
// 			temp = reverse(start);
// 			tail = start;
// 			// print(temp);
// 			tail->next = kreverse(next,k);

// 			break;

// 		}

// 		head = head->next;

// 	}

// 	return temp;


// }


int main()
{
	int k;
	cin>> k;
	Node *head = takeinput();

	head = reverse(head,k);
	print(head);

}