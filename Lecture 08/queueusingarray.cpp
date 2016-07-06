#include<iostream>
using namespace std;
#include "queue.h"


int main()
{
	
	queue<int> q;
	try{
	// cout<< " element at q is : " << q.front() << endl;
	q.enqueue(1);
	cout<< " element at q is : " << q.front() << endl;
	q.enqueue(2);
	cout<< " element at q is : " << q.front() << endl;
	q.enqueue(3);
	cout<< " element at q is : " << q.front() << endl;
	cout<< " size of q is : " << q.size() << endl;
	cout<<" is queue empty : " << q.isempty() << endl;

	q.dequeue();
	cout<< " element at q is : " << q.front() << endl;
	cout<< " size of q is : " << q.size() << endl;
	cout<<" is queue empty : " << q.isempty() << endl;

	q.dequeue();
	cout<< " element at q is : " << q.front() << endl;
	cout<< " size of q is : " << q.size() << endl;
	cout<<" is queue empty : " << q.isempty() << endl;

q.dequeue();
	cout<< " element at q is : " << q.front() << endl;
	cout<< " size of q is : " << q.size() << endl;
	cout<<" is queue empty : " << q.isempty() << endl;

}
catch(char const* str)
{
	cout<<"here "<<endl;
	cout<< str << endl;
}


return 0;
}