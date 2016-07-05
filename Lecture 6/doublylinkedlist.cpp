#include<iostream>
using namespace std;
#include<stdlib.h>
#include<conio.h>

class Node
{
	public : 

	int data;
	Node*prev;
	Node*next;

	Node(int data)
	{
		this->data = data;
		prev = NULL;
		next = NULL;


	}
	~Node()
	{
		if(next)
			delete next;
	}
};

Node* insert_beg(Node *head ,Node *&tail, int data)
{	
  Node * temp  = new Node(data);

  if(head==NULL)
  {
  	head = temp;
  	tail = temp;
  	cout<< "Node Successfully inserted in the begenning " << endl;
  	return head;
  }

  temp->next = head;
  head->prev = temp;
  head = temp;
  cout<< "Node Successfully inserted in the begenning " << endl;
  return temp;
}

Node * insert_end(Node *&head ,Node*tail , int data)
{
	Node *temp = new Node(data);

	if(tail==NULL)
	{
		head = temp;
		tail = temp;
		cout<<"Node Successfully inserted in the end " << endl;
		return head;
	}

	tail->next = temp;
	temp->prev = tail;
	tail = temp;

	cout<<"Node Successfully inserted in the end " << endl;
	return tail; 
}

Node *insert_at_k(Node *head ,Node*&tail, int data , int k )
{

	if(k==0)
		return insert_beg(head,tail,data);

	int count = 0;
	Node *start = head;
	while(head!=NULL && count<k)
	{
		head = head->next;
		count++;
	}

	// cout<< " count is : " << count << " and " << k << endl;
	if(head==NULL  )
		{	if(count ==k)
			{   	cout<<"here";
				Node *temp = new Node(data);
				tail->next = temp;
				temp->prev = tail;
				tail = temp;

				return start;
			}
			else 
				{
					cout<<" Not a valid position ";
					return start;
				}
		}



	Node*before = head->prev;
	Node *temp = new Node(data);
	temp->next = before->next;
	temp->prev =  before;
	before->next = temp;
	temp->next->prev = temp;


	return start;
}

void print_start(Node * head)
{	
	cout<<"Printing from start  \n";
	while(head!=NULL)
	{
		cout<< head->data << " -> ";
		head = head->next;
	}

	cout<<"-1" << endl;
}

void print_end	(Node * tail)
{	
	cout<<"Printing from end \n";
	
	while(tail!=NULL)
	{
		cout<< tail->data << " <- ";
		tail = tail->prev;
	}
	cout<<"-1 " ;
	cout<< endl;
}

int find_element_at_k(Node * head , int k )
{
	int count = 0;

	while(head!=NULL && count<k)
	{
		head = head->next;
		count++;
	}

	if(head==NULL) cout<<"Element does not exist !!"; return 0;
	if(count==0) return 0;
	else return head->data ;
} 

void delete_at_k(Node*&head ,Node*&tail , int k)
{
	if(head==NULL)
		{	cout<<"There is no element in the doubly linked list ";
			return ;
		}

	if(k==1)
	{
		if(head==tail)
		{
			Node *temp = head;
			temp->next = NULL;
			temp->prev = NULL;
			head = NULL;
			tail = NULL;
			delete temp;
			cout<<"Element at index " << k  << " deleted "  << endl; 
			return ;
		}

		Node *temp = head;
		head = head->next;
		if(head!=NULL)
		head->prev = NULL;
	     temp->next = NULL;
	     temp->prev = NULL;
		delete temp;
		cout<<"Element at index " << k  << " deleted " << endl; 
		return ;
	}

	int count = 0;
	Node *curr = head;
	while(curr!=NULL &&  count<k)
	{
		curr = curr->next;
		count++;
	}

	if(curr==NULL)
	{	
		if(count==k)
		{
			Node*temp = tail;
			tail = tail->prev;
			tail->next = NULL;
			temp->next=NULL;
			temp->prev=NULL;
			delete temp;
			cout<<"element deleted " << endl;
			return;
		}

		else
		cout<<"element does not exist "; return ;
	}

	Node*temp = curr;
	Node* old = curr->prev;
	if(old->next!=NULL)
	old->next = temp->next;
	if(temp!=NULL && temp->next->prev!=NULL)
	temp->next->prev = old;
	temp->next = NULL;
	temp->prev = NULL;
	delete temp;

	cout<<"element deleted " << endl;
	return ;
}

int get_num_of_elements(Node*head)
{
	int count=0;
	while(head!=NULL)
	{
		count++;
		head = head->next;
	}

	return count;
}



int main()
{	
	Node *head = NULL;
	Node *tail = NULL;
	Node *temp = NULL;
	int k;
	char ch;
	int data;
	do
	{
	cout<<"Enter your choice : ";
	cout<<"\n1: Insert element at beg \n2: Insert element at ene \n3: Print element from start to end using head";
	cout<<"\n4: Print element from end to start using tail \n5: Find element at position k \n6: Delete element from position k ";
	cout<<"\n7: Insert element at pos k :\n q: To exit : \n8: FInd number of elements : \n";
	cin>> ch;
	int k ;
	switch(ch)
	{
		case '1' :  cout<<"Enter the data to be added : "; 
					cin>> data; 
					head = insert_beg(head,tail,data); break;

		case '2' :  cout<<"Enter the data : "; 
					cin>> data; 
					tail = insert_end(head,tail,data); break;

		case '3' :  print_start(head); break;
		case '4' :  print_end(tail); break;

		case '5' :  cout<<"Enter the kth position : "; 
					cin>> data; 
					k = find_element_at_k(head,data);
					if(k==0) cout<<"Element not found !!";
					else cout<< "Element found at index : " << k+1 << endl;  break;

		case '6' : cout<<"Enter the kth number to be deleted : "; 
					cin>> k;
					delete_at_k(head,tail,k); break;

		case '7' : cout<<"Enter the data to be inserted : "; 
				   cin>> data; 
				   cout<<"\nEnter position : " ; 
				   cin>> k;  
				   head = insert_at_k(head,tail,data,k-1); break;
		case '8' : cout<< "NUmber of elements are :  " << get_num_of_elements  << endl; break;
		case 'q' : exit(0);
		default  : cout<<"incorrect input";break;

	}

	
	// system("cls");
	 
}while(ch !='q');

return 0;
}
