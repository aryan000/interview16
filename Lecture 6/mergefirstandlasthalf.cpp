/*Given a Linked List a1→a2→a3….→an→b1→b2→…..→bn. Convert it to a1→b1→a2→b2…→an→bn

Input Format : Input contains multiple numbers each with separated by a space except last ,representing each node of linked list with -1 stating as end or NULL.

Output Format: Print the output LL, each element should be separated by a space and LL end should be shown by a -1

Sample test case : 1 2 3 4 -1

Output: 1 3 2 4 -1*/





#include<iostream>
using namespace std;

class Node
{
	public : 
	int data;
	Node *next;

	Node(int data)
	{
	this->data = data;
	next=NULL;
	}

	~Node()
	{
		if(next)
			delete next;
	}
};



Node * take_input()
{
	int n;
	cin>> n;
	Node* head = NULL;
	Node *tail = NULL;

	while(n!=-1)
	{
		Node* temp = new Node(n);

		if(head==NULL)
		{
			head=temp;
			tail=temp;
			head->next=NULL;
		}

		else
		{
			tail->next = temp;
			tail = temp;
		}
		cin>>n;

	}

	return head;
}

void print(Node*head)
{
	while(head!=NULL)
	{
		cout<< head->data << " ";
		head = head->next;
	}

	cout<< -1 << endl;
}


Node * merge(Node* head1 , Node *head2)
{
	Node*temp , *temp2;
	Node *root = head1;
	while(head2!=NULL)
	{	
		temp = head1->next;
		temp2 = head2->next;
		head1->next = head2;
		head2->next = temp;
		head1 = temp;
		head2 = temp2;


	}

	// print(root);
	return root;
}

Node * merge_last_half_and_first_half(Node *head)
{	
	if(head==NULL) return head;
	Node * slow = head;
	Node * fast = head->next;
	

	while(slow!=NULL && fast!=NULL)
	{
		fast = fast->next;
		if(fast!=NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
  
   Node *b = slow->next;
   slow->next = NULL;
   // print(head);
   // print(b);
	return merge(head,b);
}

int main()
{
	Node *head = take_input();
	merge_last_half_and_first_half(head);
	print(head);
	delete head;
}