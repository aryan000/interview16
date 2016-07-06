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

Node * recursive_reverse(Node *head)
{
	if(head==NULL || head->next==NULL)
		return head;

	Node *temp = head->next;
	Node *ans = recursive_reverse(head->next);

	temp->next = head;
	head->next = NULL;
	return ans;

}

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

int main()
{
	Node *head = take_input();
	head = recursive_reverse(head);

	print(head);
}