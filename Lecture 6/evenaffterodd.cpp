#include<iostream>
using namespace std;

class Node
{	
public:

	int data;
	Node *next;

	Node(int data)
	{
		this->data = data;
		next = NULL;

	}

	~Node()
	{
		if(next)
			delete next;
	}

};


Node* takeinput()
{	
	Node *head = NULL;
	Node *tail = NULL;
	int n;
	cin>> n;
	while(n!=-1)
	{
		Node *temp = new Node(n);

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
		cout<< head->data << " ";
		head = head->next;
	}
	cout<< "-1" << endl;

}


Node * evenafterodd(Node * head)
{
	if(head==NULL)
		return head;
	Node * start_even = NULL;
	Node * start_odd = NULL;
	Node *even = NULL;
	Node *odd = NULL;
	Node *curr = NULL;

	while(head!=NULL)
	{	curr = head;
		head = head->next;
		curr->next = NULL;
		if(curr->data &1) // data is odd
		{
			if(odd==NULL) // first element 
				{
					odd = curr;
					start_odd = curr;
				}

			else
			{
				odd ->next = curr;
				odd = curr;

			}
		}

		else
		{
			if(even==NULL)
			{
				even = curr;
				start_even = curr;
			}
			else
			{
				even->next = curr;
				even = curr;
			}
		} // end of else
	} // end of while loop

	if(start_odd==NULL)
		return start_even;

	odd->next = start_even;
	return start_odd;


}

int main()
{
	Node*head = takeinput();
	head = evenafterodd(head);
	print(head);
}