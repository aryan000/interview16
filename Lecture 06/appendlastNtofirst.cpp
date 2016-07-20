/*
Append the last n elements of a linked list to the front. e.g. 1→ 2→ 3 → 4→ 5 →6→ null and n = 2 would return 5→ 6→ 1→ 2→ 3 → 4 → null

Input :Input contains a number n and in next line contains multiple numbers separated by space ending with a -1 (Null Node ).

Output : Print the output LL, each element should be separated by a space and LL end should be shown by a -1

Sample Input :

2

1 2 3 4 5 6 -1

Output

5 6 1 2 3 4 -1


*/


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




Node * append_last_n_to_first(Node *head , int n)
{	
	if(head==NULL) return head;
	Node * slow = head;
	Node * fast = head;

	int count = 0;
	
	bool flag = false;

	while(slow!=NULL && slow->next!=NULL)
	{
		slow = slow->next;
		if(count>=n)
		{
			 flag = true;
			fast = fast->next;
		}
		count++;
	}
  
  if(flag==false)
  	return head;
  
   Node *b = fast->next;
   fast->next = NULL;
slow->next = head;

// cout<< count << endl;
   // print(head);
   // print(b);
	return b;
}

int main()
{
	int n ;
	cin>> n;
	Node *head = take_input();
	head = append_last_n_to_first(head,n);
	print(head);
	delete head;
}