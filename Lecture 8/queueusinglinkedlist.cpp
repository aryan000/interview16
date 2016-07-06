#include<iostream>
using namespace std;
#include "queuelinkedlist.h"


int main()
{
	
	queue<int> q;
	
	// cout<< " element at q is : " << q.front() << endl;
	q.enqueue(1);
	cout<< " element at q is : " << q.front() << endl;
	q.enqueue(2);
	cout<< " element at q is : " << q.front() << endl;
	q.enqueue(3);
	cout<< " element at q is : " << q.front() << endl;
	cout<< " size of q is : " << q.getsize() << endl;
	cout<<" is queue empty : " << q.isempty() << endl;

	q.dequeue();
	cout<< " element at q is : " << q.front() << endl;
	cout<< " size of q is : " << q.getsize() << endl;
	cout<<" is queue empty : " << q.isempty() << endl;

	q.dequeue();
	cout<< " element at q is : " << q.front() << endl;
	cout<< " size of q is : " << q.getsize() << endl;
	cout<<" is queue empty : " << q.isempty() << endl;

q.dequeue();
	cout<< " element at q is : " << q.front() << endl;
	cout<< " size of q is : " << q.getsize() << endl;
	cout<<" is queue empty : " << q.isempty() << endl;




return 0;
}