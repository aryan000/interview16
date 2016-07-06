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

int count(Node<int>*head)
{	int count = 0;
	while(head!=NULL)
	{
		count++;
		head = head->next;
	}
	return count;
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

Node<int>* add(Node<int>* head1 , Node<int>* head2)
{
	int carry = 0;
	int n1 = count(head1);
	int n2 = count(head2);
	Node<int>* ans = head1;
	if(head1==NULL) return head2;
	if(head2==NULL) return head1;

	if(n1<n2)
		return add(head2,head1);

	// considering head1 is greater
	int temp;
	Node<int> *prev ;
	while(head1!=NULL)
	{	if(head1->next==NULL)
			prev = head1;
		if(head2!=NULL)
		{
			temp = carry + head1->data + head2->data;
			head1->data = temp%10;
			carry = temp/10;

			head1 = head1->next;
			head2 = head2->next;
			continue;

		}

		if(head2==NULL)
		{
			temp = carry + head1->data;
			head1->data = temp%10;
			carry = temp/10;
			head1 = head1->next;
		}

	}// end of while loop

	if(carry!=0)
	{
		Node<int> *lastnode = new Node<int> (carry);
		prev->next = lastnode;
	}


	return ans;
}

int main()
{
	Node<int> *head = take_linked_list_input();
	Node<int> *head2 = take_linked_list_input();
	head = iterative_reverse(head);
	head2 = iterative_reverse(head2);
	
	Node<int> * ans = add(head,head2);
	ans = iterative_reverse(ans);
	print(ans);

	// print(head);


	delete head;
	delete head2;

}